
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int K = 1e6 + 5, N = 2e5 + 5;
int t, n, k, d;
int a[N];
map<int, int> m;
set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> d;
        m.clear();
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        s.clear();
        for(int i = 0; i < d; i++) {
            m[a[i]]++;
            s.insert(a[i]);
        }
        int M = s.size();
        for(int i = d; i < n; i++) {
            m[a[i - d]]--;
            m[a[i]]++;
            if(m[a[i - d]] == 0) {
                s.erase(a[i - d]);
            }
            s.insert(a[i]);
            M = min(M, (int) s.size());
        }
        cout << M << endl;
    }
}