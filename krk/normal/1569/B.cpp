#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
string s;
char B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cin >> s;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                B[i][j] = i == j? 'X': '=';
        vector <int> seq;
        for (int i = 0; i < n; i++)
            if (s[i] == '2') seq.push_back(i);
        if (seq.size() == 1 || seq.size() == 2) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for (int i = 0; i < seq.size(); i++) {
            int ni = (i + 1) % int(seq.size());
            B[seq[i]][seq[ni]] = '+';
            B[seq[ni]][seq[i]] = '-';
        }
        for (int i = 0; i < n; i++) {
            B[i][n] = '\0';
            printf("%s\n", B[i]);
        }
    }
    return 0;
}