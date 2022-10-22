#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, k;
int a[Maxn];
char str[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%s", str);
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && str[i] == str[j]) j++;
        vector <int> tmp;
        for (int l = i; l < j; l++)
            tmp.push_back(a[l]);
        sort(tmp.rbegin(), tmp.rend());
        for (int l = 0; l < tmp.size() && l < k; l++)
            res += tmp[l];
    }
    cout << res << endl;
    return 0;
}