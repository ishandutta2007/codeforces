#include <bits/stdc++.h>
using namespace std;

char tmp[10];
int n;
string f;
map <string, int> C;
map <string, string> M;

int main()
{
    scanf("%d", &n);
    while (n--) {
        scanf("%s", tmp); f = tmp;
        set <string> S;
        for (int i = 0; i < f.size(); i++)
            for (int j = 1; i + j <= f.size(); j++) {
                string sub = f.substr(i, j);
                S.insert(sub);
            }
        for (set <string>::iterator it = S.begin(); it != S.end(); it++) {
            C[*it]++; M[*it] = f;
        }
    }
    int m; scanf("%d", &m);
    while (m--) {
        scanf("%s", tmp); f = tmp;
        map <string, int>::iterator it = C.find(f);
        if (it == C.end()) { printf("0 -\n"); }
        else printf("%d %s\n", it->second, M[f].c_str());
    }
    return 0;
}