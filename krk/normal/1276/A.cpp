#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char str[Maxn];
int n;
bool rem[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); n = strlen(str);
        fill(rem, rem + n, false);
        for (int i = 0; i + 3 <= n; i++) {
            auto tmp = string(1, str[i]) + string(1, str[i + 1]) + string(1, str[i + 2]);
            if (tmp == "one" || tmp == "two")
                rem[i + 1] = true;
        }
        for (int i = 0; i + 3 <= n; i++)
            if (rem[i] && rem[i + 2] && str[i] == 'w' && str[i + 2] == 'n') {
                rem[i] = rem[i + 2] = false;
                rem[i + 1] = true;
            }
        vector <int> res;
        for (int i = 0; i < n; i++)
            if (rem[i]) res.push_back(i);
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i] + 1, i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}