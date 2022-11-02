#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t, m; 
    cin >> t >> m;
    vector<int> mem(m, 0);
    int n = 0;
    for(int T = 0; T < t; ++T) {
            string type;
            cin >> type;
            if(type == "alloc") {
                    int sz;
                    cin >> sz;
                    for(int i = 0; i + sz <= m; ++i) {
                            bool ok = true;
                            for(int k = i; k < i + sz; ++k)
                                    if(mem[k])
                                              ok = false;
                            if(ok) {
                                   ++n;
                                   for(int k = i; k < i + sz; ++k)
                                           mem[k] = n;
                                           cout << n << endl;
                                           break;
                                   }
                            if(i + sz == m) 
                                 cout << "NULL" << endl;
                    }
                    if(sz > m) 
                          cout << "NULL" << endl;
            }
            if(type == "erase") {
                    int nn;
                    cin >> nn;
                    if(nn <= 0) {
                        cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
                        continue;
                    }
                    bool done = false;
                    for(int i = 0; i < m; ++i)
                            if(mem[i] == nn) {
                                      mem[i] = 0;
                                      done = true;
                            }
                    if(!done) {
                              cout <<  "ILLEGAL_ERASE_ARGUMENT" << endl;
                              continue;
                    } 
            }
            if(type == "defragment") {
                    int last = -1, sz = 0;
                    vector<int> cur(mem.begin(), mem.end());
                    for(int i = 0; i < m; ++i) {
                            sz++;
                            if((i == m - 1 || mem[i] != mem[i + 1])) {
                                  if(mem[i] != 0) {
                                      int t = mem[i];
                                      for(int j = i - sz + 1; j <= i; ++j)
                                             cur[j] = 0;
                                      for(int j = last + 1; j <= last + sz; ++j)
                                             cur[j] = t;
                                      last += sz;
                                  }
                                 sz = 0; 
                            }
                    }
                    mem = cur;
            }
    }
    cin >> n;
    return 0;
}