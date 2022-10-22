#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;

const int Maxn = 1000005;

int n;
int a[Maxn];
vector <ii> seq;
set <int> S;
ll delt[Maxn];
ld res[Maxn];
int m;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        seq.push_back(ii(a[i], i));
    }
    sort(seq.begin(), seq.end());
    S.insert(-1);
    S.insert(n);
    for (int i = 0; i < seq.size(); i++) {
        int ind = seq[i].second;
        set <int>::iterator it = S.insert(ind).first;
        set <int>::iterator it2 = it;
        it--; it2++;
        if (ind - *it < *it2 - ind)
            for (int i = *it + 1; i <= ind; i++) {
                delt[ind - i + 1] += a[ind];
                delt[*it2 - i + 1] -= a[ind];
            }
        else for (int i = ind; i < *it2; i++) {
                delt[i - ind + 1] += a[ind];
                delt[i - *it + 1] -= a[ind];
            }
    }
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += delt[i];
        res[i] = ld(cur) / (n - i + 1);
    }
    scanf("%d", &m);
    while (m--) {
        int num; scanf("%d", &num);
        printf("%.15f\n", double(res[num]));
    }
    return 0;
}