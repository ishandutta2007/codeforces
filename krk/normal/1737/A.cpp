#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;
const int Maxl = 26;

int T;
int n, k;
string s;
int freq[Maxl];
char res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill(freq, freq + Maxl, 0);
        cin >> s;
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;
        int len = k;
        for (int i = 0; i < Maxl; i++) {
            int f = i < n / k? freq[i]: 0;
            while (len > f)
                res[--len] = i + 'a';
        }
        res[k] = '\0';
        printf("%s\n", res);
    }
    return 0;
}