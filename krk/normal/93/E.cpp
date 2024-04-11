#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
int k;
vector <int> a;
deque <ll> x, y;
ll res;

int main()
{
    scanf("%I64d %d", &n, &k);
    a.resize(k);
    for (int i = 0; i < k; i++) scanf("%d", &a[i]);
    sort(a.rbegin(), a.rend());
    x.push_back(1LL); y.push_back(n);
    for (int i = 0; i < k; i++) {
        deque <ll> x2, y2;
        for (int j = 0; j < x.size(); j++)
            if (a[i] <= y[j]) {
                x2.push_back(-x[j]); y2.push_back(y[j] / a[i]);
            }
        deque <ll> x3, y3;
        while (!x.empty() && !x2.empty()) {
            ll tmp1, tmp2;
            if (y.front() < y2.front()) { tmp1 = x.front(); tmp2 = y.front(); x.pop_front(); y.pop_front(); }
            else { tmp1 = x2.front(); tmp2 = y2.front(); x2.pop_front(); y2.pop_front(); }
            if (!y3.empty() && y3.back() == tmp2) x3.back() += tmp1;
            else { x3.push_back(tmp1); y3.push_back(tmp2); }
        }
        while (!x.empty()) {
            if (!y3.empty() && y3.back() == y.front()) x3.back() += x.front();
            else { x3.push_back(x.front()); y3.push_back(y.front()); }
            x.pop_front(); y.pop_front();
        }
        while (!x2.empty()) {
            if (!y3.empty() && y3.back() == y2.front()) x3.back() += x2.front();
            else { x3.push_back(x2.front()); y3.push_back(y2.front()); }
            x2.pop_front(); y2.pop_front();
        }
        x = x3; y = y3;
    }
    for (int i = 0; i < x.size(); i++) res += x[i] * y[i];
    printf("%I64d\n", res);
    return 0;
}