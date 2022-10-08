
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int p[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

const int N = 1005;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < 11; j++) {
                if(a[i] % p[j] == 0) {
                    a[i] = j;
                    break;
                }
            }
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        cout << v.size() << '\n';
        for(int i = 0; i < n; i++) {
            cout << lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1 << " ";
        }
        cout << '\n';
    }
}