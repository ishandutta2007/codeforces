
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
    vi ans(51, -1);
    rep(len, 1, 10) {
        vi perm(9, 1);
        rep(i, 0, len - 1) perm[i] = 0;
        do {
            int num = 0, sum = 0;
            rep(i, 0, 9) {
                if(perm[i]) {
                    num = 10 * num + i + 1;
                    sum += i + 1;
                }
            }
            if(sum <= 50 && (ans[sum] == -1 || num < ans[sum])) {
                ans[sum] = num;
            }
        }while(next_permutation(all(perm)));
    }
    while(te--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}