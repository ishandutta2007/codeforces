
#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x),end()
#define sz(x) ((int) (x).size())
#define pii pair<int, int>
#define vi vector<int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)

using namespace std;

vi A, B, A1, B1, A2, B2;

void solve(ll a, ll b, vi &A, vi &B) {
    set<ll> se;
    ll i = 0;
    while(i * (i + 1) / 2 < a + b) {
        i++;
        se.insert(i);
    }
    if(i * (i + 1) / 2 - a - b > 0) se.erase(i * (i + 1) / 2 - a - b);
    while(b > 0) {
        set<ll>::iterator it;
        if((it = se.lower_bound(b + 1)) != se.begin()) {
            it = prev(it);
            b -= *it;
            B.push_back(*it);
            se.erase(it);
        }else break;
    }
    while(a > 0) {
        set<ll>::iterator it;
        if((it = se.lower_bound(a + 1)) != se.begin()) {
            it = prev(it);
            a -= *it;
            A.push_back(*it);
            se.erase(it);
        }else break;
    }

    /*
    ll i = 0;
    while(i * (i + 1) / 2 < a + b) i++;
    // remove number i(i + 1) / 2 - a - b
    ll j = 0, sum = 0;
    while(sum < a) {
        j++;
        if(j != i * (i + 1) / 2 - a - b) {
            A.push_back(j);
            sum += j;
        }
    }
    // move sum - a to B.
    if(sum - a == i * (i + 1) / 2 - a - b) {
        // special case
        if(sum - a == 1) {
            // 1 already removed, replace 2 with 1 and forget about it
            A[0] = 1;
            rep(k, j + 1, i + 1) B.push_back(k);
        }else if(sum - a == 2) {
            
        }else {
            // split as 1 and sum - a - 1
            A.erase(find(all(A), 1));
            A.erase(find(all(A), 
        }
    }else {
        A.erase(find(all(A), sum - a));
        B.push_back(sum - a);
        rep(k, j + 1, i + 1) {
            B.push_back(k);
        }
    }*/
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    if(a > b) {
        solve(b, a, B, A);
        if(b>0) solve(b - 1, a, B1, A1);
        if(a>0) solve(b, a - 1, B2, A2);
    }else {
        solve(a, b, A, B);
        if(a>0) solve(a - 1, b, A1, B1);
        if(b>0) solve(a, b - 1, A2, B2);
    }
    if(sz(A1) + sz(B1) > sz(A) + sz(B)) {
        A.swap(A1); B.swap(B1);
    }
    if(sz(A2) + sz(B2) > sz(A) + sz(B)) {
        A.swap(A2); B.swap(B2);
    }
    cout << sz(A) << '\n';
    for(int x : A) cout << x << ' ';
    cout << '\n';
    cout << sz(B) << '\n';
    for(int x : B) cout << x << ' ';
    cout << '\n';
}