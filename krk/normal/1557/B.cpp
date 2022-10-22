#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, k;
vector <int> un;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        un.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            un.push_back(a[i]);
        }
        sort(un.begin(), un.end());
        for (int i = 0; i < n; i++)
            a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        int res = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && a[j] - a[i] == j - i) j++;
            res++;
        }
        printf("%s\n", res <= k? "Yes": "No");
    }
    return 0;
}