#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100100;

int a[maxn];
int b[maxn];

pii ans[2000010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i){
        int v; scanf("%d", &v);
        b[v] = i;
    }

    for (int i = 1; i <= n; ++i){
        a[i] = b[a[i]];
    }


    int64 value = 0;
    int k = 0;

    for (int i = 1; i <= n; ++i){
        int pos = i;
        for (;a[pos] != i; ++pos);
        int cpos = pos;
        if (pos == i) continue;
        for (;pos != i - 1; --pos){
            if (a[pos] >= cpos){
                value += cpos - pos;
                ans[k++] = pii(cpos, pos);
                a[cpos] = a[pos];
                a[pos] = i;
                cpos = pos;
            }
        }
    }

    printf("%I64d\n%d\n", value, k);
    for (int i = 0; i < k; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}