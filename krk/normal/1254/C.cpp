#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 1005;

int n;
int mn = 2;
vector <lli> srt;
vector <int> seq1, seq2;

ll Ask(int t, int i, int j, int k)
{
    printf("%d %d %d %d\n", t, i, j, k); fflush(stdout);
    ll res; scanf("%I64d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 3; i <= n; i++)
        if (Ask(2, 1, i, mn) > 0) mn = i;
    for (int i = 2; i <= n; i++) if (i != mn)
        srt.push_back(lli(Ask(1, 1, mn, i), i));
    sort(srt.begin(), srt.end());
    int mx = srt.back().second;
    for (int i = int(srt.size()) - 2; i >= 0; i--)
        if (Ask(2, 1, srt[i].second, mx) > 0) seq1.push_back(srt[i].second);
        else seq2.push_back(srt[i].second);
    printf("0 1 %d", mn);
    for (int i = int(seq1.size()) - 1; i >= 0; i--)
        printf(" %d", seq1[i]);
    printf(" %d", mx);
    for (int i = 0; i < seq2.size(); i++)
        printf(" %d", seq2[i]);
    printf("\n"); fflush(stdout);
    return 0;
}