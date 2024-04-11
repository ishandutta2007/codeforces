#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;
typedef pair <ll, llll> llllll;

const ll lim = 2000000000000000000ll;
const int Maxn = 200005;

int n, k;
int a[Maxn];
deque <llllll> D;
ll res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        while (!D.empty() && D.front().first > lim / a[i])
            D.pop_front();
        for (int j = 0; j < D.size(); j++) {
            D[j].first *= a[i];
            D[j].second.first += a[i];
            D[j].second.second += a[i];
        }
        if (a[i] > 1) D.push_back(llllll(a[i], llll(a[i], a[i])));
        else if (!D.empty() && D.back().first == 1) D.back().second.first = 1;
        else D.push_back(llllll(a[i], llll(a[i], a[i])));
        for (int j = 0; j < D.size(); j++) {
            if (D[j].first % k == 0) {
                ll nd = D[j].first / k;
                if (D[j].second.first <= nd && nd <= D[j].second.second)
                    res++;
            }
        }
    }
    printf("%I64d\n", res);
    return 0;
}