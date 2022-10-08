
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int n, m;
int a[N], b[N];
string s;
map<string, int> f;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < m; i++) {
        cin >> s;
        f[s]++;
    }
    for(auto p : f) {
        v.push_back(p.second);
    }
    sort(v.rbegin(), v.rend());
    int msum = 0, Msum = 0;
    for(int i = 0; i < (int) v.size(); i++) {
        msum += a[i] * v[i];
        Msum += a[n - i - 1] * v[i];
    }
    cout << msum << " " << Msum << endl;
}