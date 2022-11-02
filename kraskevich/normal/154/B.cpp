#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> u(n + 1, false);
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for(int i = 2; i * i <= n; ++i)
            if(p[i])
                    for(int j = i * i; j <= n; j += i)
                            p[j] = false;
    vector<set<int> > num(n + 1);
    for(int i = 0; i <= n; ++i)
            num[i].clear();
    int m;
    cin >> m;
    vector<char> type(m);
    vector<int> pos(m);
    for(int i = 0; i < m; ++i)
            cin >> type[i] >> pos[i];
    for(int i = 0; i < m; ++i) {
             char c = type[i];
             int t = pos[i];
             if(c == '-') {
                  if(u[t] == false) {
                            cout << "Already off" << endl;
                            continue;
                  }
                  else {
                       u[t] = false;
                       int cur = t;
                       for(int j = 2; j * j <= t; ++j)
                               if(p[j] && t % j == 0) {
                                    while(cur % j == 0)
                                              cur /= j;
                                    num[j].erase(t);
                               }
                       if(p[t])
                               num[t].erase(t);
                       if(p[cur] && cur >= 2 && cur != t)
                                 num[cur].erase(t);
                       cout << "Success" << endl;
                       continue;
                  }
             }
             if(c == '+') {
                  if(u[t]) {
                           cout << "Already on" << endl;
                           continue;
                  }
                  else {
                       bool ok = true;
                       int cur = t;
                       for(int j = 2; j * j <= t && ok; ++j) {
                               if(t % j == 0 && p[j] && num[j].size() > 0) {
                                    cout << "Conflict with " << *num[j].begin() << endl;
                                    ok = false;
                               }
                               if(t % j == 0)
                                    while(cur % j == 0)
                                              cur /= j;
                       }
                       if(cur >= 2 && p[cur] && num[cur].size() > 0 && ok) {
                                   cout << "Conflict with " << *num[cur].begin() << endl;
                                   ok = false;
                       }
                       if(ok) {
                              u[t] = true;
                              int cur = t;
                              for(int j = 2; j * j <= t; ++j)
                                      if(t % j == 0 && p[j]) {
                                           while(cur % j == 0)
                                                     cur /= j;
                                           num[j].insert(t);
                                      }
                              if(p[t])
                                      num[t].insert(t);
                              if(p[cur] && cur >= 2 && cur != t)
                                        num[cur].insert(t);
                              cout << "Success" << endl;
                       }
                  }
             }
    }
    cin >> n;
    return 0;
}