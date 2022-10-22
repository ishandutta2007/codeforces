#include <bits/stdc++.h>
using namespace std;

const int Maxn = 15;

int t;
int n;
set <string> S;
string s[Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        S.clear();
        scanf("%d", &n);
        int res = 0;
        vector <int> V;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            if (S.find(s[i]) != S.end()) V.push_back(i);
            else S.insert(s[i]);
        }
        res = int(V.size());
        for (int i = 0; i < V.size(); i++) {
            int ind = V[i];
            for (s[ind][0] = '0'; s[ind][0] <= '9'; s[ind][0]++)
                if (S.find(s[ind]) == S.end()) break;
            S.insert(s[ind]);
        }
        printf("%d\n", res);
        for (int i = 0; i < n; i++)
            printf("%s\n", s[i].c_str());
    }
    return 0;
}