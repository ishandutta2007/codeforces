
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

const int N = 2e5 + 5;
int n, k;
int a[N];

int check(vi &v, int k) {
    if(k < 0) return -1e9;
    int a = 0;
    for(int x : v) {
        if(x == 0) continue;
        if(k - x < 0) break;
        else {
            a += 2;
            k -= x;
        }
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int cnt = 0;
    int ans = 0;
    rep(i, 0, n) {
        cin >> a[i];
        ans += ((i == 0 && a[i] < 0) || (i > 0 && (a[i] < 0) != (a[i - 1] < 0)));//i == 0 || a[i - 1] >= 0));
    }
    vi ve;
    int val1 = 0;
    bool reach = false;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] < 0) {
            if(reach)
                ve.push_back(cnt);
            else val1 = cnt;
            cnt = 0;
            k--;
            reach = true;
        }else {
            cnt++;
        }
    }
    if(k < 0) {
        cout << "-1\n";
        return 0;
    }
    sort(all(ve));
    int A = min(ans - check(ve, k), val1 > 0 ? ans - check(ve, k - val1) - 1 : (int) 1e9);
    cout << A << '\n';
}