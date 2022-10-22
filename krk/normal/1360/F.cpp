#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;
map <string, int> M;

int main()
{
    cin >> T;
    while (T--) {
        M.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                string cur = s;
                for (cur[j] = 'a'; cur[j] <= 'z'; cur[j]++) if (cur[j] != s[j])
                    M[cur]++;
            }
            M[s]++;
        }
        string res = "";
        for (map <string, int>::iterator it = M.begin(); it != M.end(); it++)
            if (it->second == n) res = it->first;
        if (res.size() == 0) printf("-1\n");
        else printf("%s\n", res.c_str());
    }
    return 0;
}