#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int tot = 0;
        for (int i=0; i<n; i++) 
            tot += s[i] == '1';
        if (tot % 2 || tot == 0) {
            cout << "NO" << endl;
            continue;
        }
        if (n == 2) {
            cout << "YES" << endl;
            cout << "1 2" << endl;
            continue;
        }
        for (int i=0; i<n; i++)
            a[i] = s[i] == '1';
        vector<int> ends;
        vector<pair<int,int>> ans;
        int x=-1, y=-1;
        for (int i=0; i<n; i++) {
            if (a[i]) {
                if (x == -1) {
                    x = i;
                    ends.push_back(i);
                    continue;
                }
                if (y == -1) {
                    y = i;
                    ends.push_back(i);
                    continue;
                }
                // connect a[i] with a[i+1]
                a[i] ^= 1;
                a[(i+1)%n] ^= 1;
                ans.push_back({i,(i+1)%n});
            } else {
                ends.push_back(i);
            }
        }

        if (x == -1 && y == -1) {
            cout << "YES" << endl;
            for (auto p : ans)
                cout << p.fi+1 << " " << p.se+1 << endl;
            continue;
        }

        if (y == -1) {
            cout << "NO" << endl;
            continue;
        }

        // all a[i] = 0 except a[x] = a[y] = 1
        for (int i=0; i<ends.size(); i++) {
            int u = ends[i];
            int v = ends[(i+1)%ends.size()];
            if (v != x && v != y) {
                ans.push_back({u,v});
                continue;
            } 
            if (v == x) {
                int j = (i+2)%ends.size();
                while (ends[j] != y)
                    j = (j+1)%ends.size();
                j = (j+ends.size()-1)%ends.size();
                ans.push_back({u,ends[j]});
            }
        }

        cout << "YES" << endl;
        for (auto p : ans)
            cout << p.fi+1 << " " << p.se+1 << endl;
    }
}