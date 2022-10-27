#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
char s[nax];
int occ[26];
int main() {
    int T;
    
    for (cin >> T ; T -- ;) {
        cin >> s;
        int n = strlen(s);
        memset(occ, 0x3f, sizeof(occ));
        for (int i = 0 ; i < n ; ++ i) {
            int v = s[i] - 'a';
            occ[v] = occ[v] > n ? i : max(occ[v], i);
        }
        int where = *min_element(occ, occ + 26);
        cout << (s + where) << '\n';
    }
}