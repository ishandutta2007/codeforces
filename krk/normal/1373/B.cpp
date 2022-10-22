#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        int res = 0;
        vector <char> S;
        for (int i = 0; i < slen; i++)
            if (S.empty() || S.back() == str[i])
                S.push_back(str[i]);
            else {
                res++;
                S.pop_back();
            }
        printf("%s\n", res % 2? "DA": "NET");
    }
    return 0;
}