#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2005;

int n, x[MAXN], y[MAXN];
ll ans;

bool cmp(pii p1, pii p2) {
    return p1.first*p2.second < p2.first*p1.second;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> x[i] >> y[i];

    for (int i=0; i<n; i++) {
        vector<pii> v;
        for (int j=0; j<n; j++)
            if (i!=j) {
                pii p = pii(x[i]-x[j], y[i]-y[j]);
                if (p.second < 0) p.first *= -1, p.second *= -1;
                if (p.first == 0) p.second = 1;
                if (p.second == 0) p.first = 1;
                v.push_back(p);
            }
        sort(v.begin(), v.end(), cmp);

        for (int j=0, k=0; j<v.size(); j=k) {
            for (k=j; k<v.size() && !cmp(v[j], v[k]) && !cmp(v[k], v[j]); k++);
            ans += ll(k-j)*(k-j-1)/2;
        }
    }
    ans /= 3;

    cout << ll(n)*(n-1)*(n-2)/6 - ans;
}