#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Fit(i,v) for(typeof(v.begin()) i=v.begin();i!=v.end();++i)

typedef vector<int> VI;

struct Dir {
  map<string, Dir*> dirs;
  Dir* parent;
  Dir() {
    parent = NULL;
  }
  string find(Dir* dir) {
    Fit(i,dirs) if(i->second==dir) return i->first;
    return "EM SAI";
  }
  string path() {
    if (parent == NULL) return "/";
    else return parent->path() + parent->find(this) + "/";
  }
};

Dir* root;

void cd(Dir* &dir, string path) {
  if (path[0] == '/') {
    path = path.substr(1);
    dir = root;
  }
  while(path.length() > 0) {
    int pos = path.find('/');
    string cur;
    if (pos == string::npos) {
      cur = path;
      path = "";
    } else {
      cur = path.substr(0, pos);
      path = path.substr(pos + 1);
    }
    if(cur == "..") dir = dir->parent;
    else {
      if (!dir->dirs.count(cur)) {
        dir->dirs[cur] = new Dir();
        dir->dirs[cur]->parent = dir;
      }
      dir = dir->dirs[cur];
    }
  }
}

int main() {
  int n_commands;
  cin >> n_commands;
  root = new Dir();
  Dir* cur_dir = root;
  Rep(ii,n_commands) {
    string command;
    cin >> command;
    if (command == "pwd") cout << cur_dir->path() << endl;
    else {
      string path;
      cin >> path;
      cd(cur_dir, path);
    }
  }
  return 0;
}