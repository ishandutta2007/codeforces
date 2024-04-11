#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

const int Maxn = 200005;
const string vowels = "AEIOU";

char s[Maxn];
int n;
int sum[Maxn], best[Maxn];
int res1, res2;

int Num(char c)
{
    return vowels.find(toupper(c)) != string::npos? -1: 2;
}

int main()
{
    scanf("%s", s); n = strlen(s);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + Num(s[i - 1]);
    best[n] = sum[n];
    for (int i = n - 1; i > 0; i--) best[i] = max(sum[i], best[i + 1]);
    int j = 0;
    for (int i = 0; i <= n; i++) {
        while (j <= n && sum[i] <= best[j]) j++;
        int cand = j - i - 1;
        if (cand > res1) { res1 = cand; res2 = 0; }
        if (cand == res1) res2++;
    }
    if (res1) printf("%d %d\n", res1, res2);
    else printf("No solution\n");
    return 0;
}