#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxl = 26;

int T;
char str[Maxn];
int slen;
vector <int> V[Maxl];
bool rem[Maxn];
char res[Maxn];
int rlen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); slen = strlen(str);
        fill(rem, rem + slen, false);
        for (int i = 0; i < Maxl; i++)
            V[i].clear();
        int sum; scanf("%d", &sum);
        sum = -sum;
        for (int i = 0; i < slen; i++) {
            sum += int(str[i] - 'a' + 1);
            V[str[i] - 'a'].push_back(i);
        }
        for (int i = Maxl - 1; i >= 0; i--)
            while (!V[i].empty() && sum > 0) {
                sum -= (i + 1);
                rem[V[i].back()] = true;
                V[i].pop_back();
            }
        rlen = 0;
        for (int i = 0; i < slen; i++)
            if (!rem[i]) res[rlen++] = str[i];
        res[rlen] = '\0';
        printf("%s\n", res);
    }
    return 0;
}