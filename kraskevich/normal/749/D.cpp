#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 400 * 1000;

int a[N];
int b[N];
vector<int> at[N];
vector<pii> ps;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        --a[i];
        at[a[i]].push_back(b[i]);    
    }
    for (int i = 0; i < n; i++)
        if (at[i].size())
            ps.push_back(pii(at[i].back(), i));
    sort(ps.begin(), ps.end());
    reverse(ps.begin(), ps.end());
    int q;
    cin >> q;
    for (int qq = 0; qq < q; qq++) {
        set<int> bad;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            x--;
            bad.insert(x);        
        }
        int p = 0;
        while (p < ps.size() && bad.count(ps[p].second))
            p++;
        if (p == ps.size()) {
            cout << "0 0\n";
            continue;
        }
        int f = p + 1;
        while (f < ps.size() && bad.count(ps[f].second))
            f++;
        cout << ps[p].second + 1 << " ";
        if (f == ps.size())
            cout << at[ps[p].second][0] << "\n";
        else
            cout << *upper_bound(at[ps[p].second].begin(), at[ps[p].second].end(), at[ps[f].second].back()) << "\n";        
    }
}