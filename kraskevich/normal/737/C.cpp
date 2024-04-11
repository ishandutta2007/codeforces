#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> h;

bool can(int want) {
    if (want == 0)
        return true;
    vector<int> good;
    for (int i = 0; i < h.size(); i++)
        if (h[i] > 0 && good.size() < want)
            good.push_back(h[i]);
    int have = (int)h.size() - want;
    if (good.size() < want)
        return false;
    int need = 0;
    int last = 0;
    for (int i = 0; i < good.size(); i++) {
        need += max(0, good[i] - last - 1);
        last = good[i];
    }
    return need <= have;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    int add = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i == s) {
            if (x != 0)
                add = 1;
            continue;
        }
        h.push_back(x);
    }
    sort(h.begin(), h.end());
    int lo = 0;
    int hi = n;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (can(mid))
            lo = mid;
        else
            hi = mid;    
    }
    cout << n - lo - 1 + add << endl;
}