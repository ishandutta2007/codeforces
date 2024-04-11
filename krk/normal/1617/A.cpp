#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int T;
char str[105];
int slen;
int cnt[Maxl];
int r[Maxl];
char oth[5];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); slen = strlen(str);
        fill(cnt, cnt + Maxl, 0);
        for (int i = 0; i < Maxl; i++)
            r[i] = i;
        for (int i = 0; i < slen; i++)
            cnt[str[i] - 'a']++;
        scanf("%s", oth); string tmp = oth;
        if (tmp == "abc" && cnt[0] > 0) swap(r[1], r[2]);
        for (int i = 0; i < Maxl; i++) {
            int cur = r[i];
            while (cnt[cur]--)
                printf("%c", cur + 'a');
        }
        printf("\n");
    }
    return 0;
}