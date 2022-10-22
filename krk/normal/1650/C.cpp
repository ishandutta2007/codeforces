#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n, m;
int X[Maxn], W[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector <ii> seq;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &X[i], &W[i]);
            seq.push_back(ii(W[i], i));
        }
        sort(seq.begin(), seq.end());
        int sum = 0;
        vector <ii> seq2;
        for (int i = 0; i < 2 * n; i++) {
            sum += seq[i].first;
            int ind = seq[i].second;
            seq2.push_back(ii(X[ind], ind));
        }
        sort(seq2.begin(), seq2.end());
        printf("%d\n", sum);
        for (int i = 0; i < n; i++)
            printf("%d %d\n", seq2[i].second + 1, seq2[2 * n - 1 - i].second + 1);
    }
    return 0;
}