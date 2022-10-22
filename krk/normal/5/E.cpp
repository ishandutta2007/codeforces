#include <cstdio>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

ll res;

void Insert(deque <int> &D, int val)
{
    while (!D.empty() && val > D.front()) D.pop_front();
    D.push_front(val);
}

void Erase(deque <int> &D, int val)
{
    if (D.back() == val) D.pop_back();
}

ll getCnt(const deque <int> &D, int val)
{
    int ind = upper_bound(D.begin(), D.end(), val) - D.begin();
    if (ind == D.size()) return D.size();
    return ind + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector <int> h(n);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    deque <int> D;
    for (int i = 1; i < n; i++) Insert(D, h[i]);
    for (int i = 0; i < n; i++) {
        res += getCnt(D, h[i]);
        Erase(D, h[(i + 1) % n]);
        Insert(D, h[i]);
    }
    D.clear();
    for (int i = n - 2; i >= 0; i--) Insert(D, h[i]);
    for (int i = n - 1; i >= 0; i--) {
        res += getCnt(D, h[i]);
        Erase(D, h[(i - 1 + n) % n]);
        Insert(D, h[i]);
    }
    map <int, int> M;
    for (int i = 0; i < n; i++) M[h[i]]++;
    ll cnt = M.rbegin()->second;
    if (cnt > 1LL) res -= cnt * (cnt - 1LL);
    else {
        M.erase(M.rbegin()->first);
        cnt = M.empty()? 0LL: M.rbegin()->second;
        res -= 2LL * cnt;
    }
    res /= 2LL;
    printf("%I64d\n", res);
    return 0;
}