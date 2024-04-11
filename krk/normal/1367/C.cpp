#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        slen = strlen(str);
        vector <int> seq;
        for (int i = 0, j; i < slen; i = j) {
            j = i;
            while (j < slen && str[i] == str[j]) j++;
            if (str[i] == '0') seq.push_back(j - i);
        }
        int res = 0;
        if (seq.empty()) { printf("0\n"); continue; }
        if (str[0] == '0' && seq[0] >= k + 1) {
            res++;
            seq[0]--;
        }
        if (str[slen - 1] == '0' && seq.back() >= k + 1 || seq.back() == slen && res == 0) {
            res++;
            seq.back()--;
        }
        for (int i = 0; i < seq.size(); i++)
            while (seq[i] >= 2 * k + 1) {
                res++;
                seq[i] -= (k + 1);
            }
        printf("%d\n", res);
    }
    return 0;
}