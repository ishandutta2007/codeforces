#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct widget {
  int type;
  long long border;
  long long spacing;
  long long width;
  long long height;
  vector<string> children;
};

map<string, widget> mp;
set<string> vis;

void packwid(const string& s, widget& w) {
  if(!vis.insert(s).second || w.type == 0) return;

  if(w.children.empty()) {
    w.width = w.height = 0;
    return;
  }

  if(w.type == 1) {
    for(int i = 0; i < w.children.size(); i++) {
      widget& wc = mp[w.children[i]];
      packwid(w.children[i], wc);

      w.width += wc.width;
      w.height = max(w.height, wc.height);
    }
    w.width += (w.children.size() - 1) * w.spacing;
  } else {
    for(int i = 0; i < w.children.size(); i++) {
      widget& wc = mp[w.children[i]];
      packwid(w.children[i], wc);

      w.height += wc.height;
      w.width = max(w.width, wc.width);
    }
    w.height += (w.children.size() - 1) * w.spacing;
  }
  w.width += 2 * w.border;
  w.height += 2 * w.border;
}

int main() {
  int N; cin >> N; cin.get();
  for(int i = 0; i < N; i++) {
    string ln; getline(cin, ln);
    for(int i = 0; i < ln.size(); i++) {
      if(ln[i] == '.' || ln[i] == '(' || ln[i] == ')' || ln[i] == ',') {
        ln[i] = ' ';
      }
    }
    istringstream sin(ln);
    
    string cmd; sin >> cmd;
    if(cmd == "Widget") {
      string name; long long x, y;
      sin >> name >> x >> y;
      widget& w = mp[name];
      w.type = 0; w.width = x; w.height = y;
    } else if(cmd == "HBox") {
      string name; sin >> name;
      widget& w = mp[name];
      w.type = 1; w.border = w.spacing = 0;
    } else if(cmd == "VBox") {
      string name; sin >> name;
      widget& w = mp[name];
      w.type = 2; w.border = w.spacing = 0;
    } else {
      string name1 = cmd;
      sin >> cmd;
      if(cmd == "pack") {
        string name2; sin >> name2;
        mp[name1].children.push_back(name2);
      } else if(cmd == "set_border") {
        long long x; sin >> x;
        mp[name1].border = x;
      } else if(cmd == "set_spacing") {
        long long x; sin >> x;
        mp[name1].spacing = x;
      } else {
        cerr << "Parse fail" << endl;
      }
    }
  }

  for(typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++) {
    widget& w = it->second;
    packwid(it->first, w);
    cout << it->first << ' ' << w.width << ' ' << w.height << endl;
  }
}