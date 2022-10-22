#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

struct widget {
       ll x, y;
       short typ;
       int border, spacing;
       bool ok;
       vector <widget*> has;
       void recSize() {
           if (!ok) {
                    x = y = 0;
                    if (!has.empty()) {
                                      for (int i = 0; i < has.size(); i++) {
                                          has[i]->recSize();
                                          if (typ == 1) {
                                                  x += has[i]->x;
                                                  y = max(y, has[i]->y);
                                          } else {
                                                 y += has[i]->y;
                                                 x = max(x, has[i]->x);
                                          }
                                      }
                                      if (typ == 1) x += (has.size() - 1) * spacing;
                                      else y += (has.size() - 1) * spacing;
                                      x += 2 * border;
                                      y += 2 * border;
                    }
                    ok = true;
           } 
       }
};

int n;
map <string, widget> M;

ll toInt(const string &s)
{
   stringstream ss(s);
   ll res; ss >> res;
   return res;
}

void Widget(const string &name, ll x, ll y)
{
     widget w;
     w.x = x; w.y = y; w.ok = true;
     M[name] = w;
}

void HBox(const string &name)
{
     widget w;
     w.typ = 1; w.border = w.spacing = 0; w.ok = false;
     M[name] = w;
}

void VBox(const string &name)
{
     widget w;
     w.typ = 2; w.border = w.spacing = 0; w.ok = false;
     M[name] = w;
}

void Pack(const string &name, const string &sname)
{
     M[name].has.push_back(&M[sname]);
}

void setBorder(const string &name, ll val)
{
     M[name].border = val;
}

void setSpacing(const string &name, ll val)
{
     M[name].spacing = val;
}

int main()
{
    cin >> n; cin.ignore();
    string s;
    while (n--) {
          getline(cin, s);
          if (s.find('.') == string::npos) {
                          int pos = s.find_last_of(' ');
                          if (s[0] == 'W') {
                                   int opos = s.find('('), cpos = s.find(')');
                                   int p = s.find(',');
                                   Widget(s.substr(pos + 1, opos - pos - 1),
                                          toInt(s.substr(opos + 1, p - opos - 1)),
                                          toInt(s.substr(p + 1, cpos - p - 1)));
                          } else if (s[0] == 'H') HBox(s.substr(pos + 1));
                          else if (s[0] == 'V') VBox(s.substr(pos + 1));
          } else {
                 int dpos = s.find('.'), opos = s.find('('), cpos = s.find(')');
                 if (s[dpos + 1] == 'p') Pack(s.substr(0, dpos), s.substr(opos + 1, cpos - opos - 1));
                 else if (s[dpos + 5] == 'b') setBorder(s.substr(0, dpos),
                                                        toInt(s.substr(opos + 1, cpos - opos - 1)));
                 else if (s[dpos + 5] == 's') setSpacing(s.substr(0, dpos),
                                                         toInt(s.substr(opos + 1, cpos - opos - 1)));
          }
    }
    for (map <string, widget>::iterator it = M.begin(); it != M.end(); it++) {
        it->second.recSize();
        cout << it->first << " " << it->second.x << " " << it->second.y << endl;
    }
    return 0;
}