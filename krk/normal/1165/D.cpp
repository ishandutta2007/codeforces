#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int n;
vector <ll> divs;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        divs.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &divs[i]);
        sort(divs.begin(), divs.end());
        ll res = ll(divs[0]) * divs.back();
        vector <ll> my;
        for (int i = 2; ll(i) * i <= res; i++) if (res % i == 0) {
            my.push_back(i);
            if (res / i != i) my.push_back(res / i);
        }
        sort(my.begin(), my.end());
        if (my != divs) printf("-1\n");
        else printf("%I64d\n", res);
    }
    return 0;
}