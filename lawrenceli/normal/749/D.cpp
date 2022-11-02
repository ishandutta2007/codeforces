#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 200100;

int n, q;
pair<int, int> ar[maxn];
vector<int> v[maxn];
priority_queue<pair<int, int> > pq;

int qk;
set<int> qs;

bool check(int k) {
    int sum = 0;
    for (int x : qs) {
        int num = v[x].end() - lower_bound(v[x].begin(), v[x].end(), k);
        sum += num;
    }

    return sum == n - k;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i].A >> ar[i].B;
        v[ar[i].A].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        if (!v[i].empty())
            pq.push(MP(v[i].back(), i));

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> qk;
        qs.clear();
        for (int j = 0; j < qk; j++) {
            int x; cin >> x;
            qs.insert(x);
        }
        
        vector<pair<int, int> > popped;
        int x = -1;
        while (!pq.empty()) {
            pair<int, int> p = pq.top(); pq.pop();
            popped.push_back(p);

            if (qs.find(p.B) == qs.end()) {
                x = p.B;
                break;
            }
        }

        qs.insert(x);
/*
        cout << popped.size() << ' ';
        for (auto j : qs) cout << j << ' ';
        cout << endl;
*/
        for (auto j : popped) pq.push(j);

        if (x == -1) {
            cout << "0 0\n";
            continue;
        }

        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }

        lo = *lower_bound(v[x].begin(), v[x].end(), lo);
        cout << ar[lo].A << ' ' << ar[lo].B << '\n';
    }
}