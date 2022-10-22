#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

set <string> S;
string col, s;
int res;

void Roll1(string &s)
{
     char tmp = s[1]; s[1] = s[2]; s[2] = s[3]; s[3] = s[4]; s[4] = tmp;
}

void Roll2(string &s)
{
     char tmp = s[0]; s[0] = s[3]; s[3] = s[5]; s[5] = s[1]; s[1] = tmp;
}

int main()
{
    cin >> col; s.resize(6);
    vector <int> V;
    for (int i = 0; i < 6; i++) V.push_back(i);
    do {
        for (int i = 0; i < 6; i++) s[i] = col[V[i]];
        if (S.find(s) == S.end()) {
                      res++;
                      for (int i = 0; i < 4; i++) {
                          for (int j = 0; j < 4; j++) {
                              S.insert(s);
                              Roll2(s);
                          }
                          Roll1(s);
                      }
                      Roll2(s);
                      for (int i = 0; i < 4; i++) {
                          for (int j = 0; j < 4; j++) {
                              S.insert(s);
                              Roll2(s);
                          }
                          Roll1(s);
                      }
        }
    } while (next_permutation(V.begin(), V.end()));
    cout << res << endl;
    return 0;
}