#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

int n, k;
char str[Maxn];
int freq[Maxl];

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        freq[str[i] - 'A']++;
    int res = freq[0];
    for (int i = 1; i < k; i++)
        res = min(res, freq[i]);
    cout << res * k << endl;
    return 0;
}