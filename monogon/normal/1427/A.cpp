
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vi a(n);
        vi pos, neg;
        int sumpos = 0, sumneg = 0;
        int sum = 0, z = 0;
        rep(i, 0, n) {
            cin >> a[i];
            sum += a[i];
            if(a[i] > 0) {
                pos.push_back(a[i]);
                sumpos += a[i];
            }
            else if(a[i] < 0) {
                neg.push_back(a[i]);
                sumneg -= a[i];
            }
            else z++;
        }
        if(sum == 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if(sumpos > sumneg) {
            for(int x : pos) cout << x << ' ';
            while(z--) cout << 0 << ' ';
            for(int x : neg) cout << x << ' ';
        }else {
            for(int x : neg) cout << x << ' ';
            while(z--) cout << 0 << ' ';
            for(int x : pos) cout << x << ' ';
        }
        cout << '\n';
    }
}