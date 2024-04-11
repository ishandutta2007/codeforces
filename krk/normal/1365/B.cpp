#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int T;
int n;
int a[Maxn], b[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        vector <int> seq1, seq2;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            if (b[i] == 0) seq1.push_back(a[i]);
            else seq2.push_back(a[i]);
        }
        vector <int> tmp1 = seq1, tmp2 = seq2;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        printf("%s\n", !tmp1.empty() && !tmp2.empty() || tmp1 == seq1 && tmp2 == seq2? "Yes": "No");
    }
    return 0;
}