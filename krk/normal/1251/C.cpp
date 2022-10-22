#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
char str[Maxn];
int slen;
vector <char> V[2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); slen = strlen(str);
        V[0].clear(); V[1].clear();
        for (int i = 0; i < slen; i++)
            V[(str[i] - '0') % 2].push_back(str[i]);
        int a = 0, b = 0;
        while (a < V[0].size() || b < V[1].size())
            if (a < V[0].size() && (b >= V[1].size() || V[0][a] < V[1][b])) {
                printf("%c", V[0][a]); a++;
            } else { printf("%c", V[1][b]); b++; }
        printf("\n");
    }
    return 0;
}