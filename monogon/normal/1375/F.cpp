
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

ll a, b, c;
ll arr[3];

void fillarray() {
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    sort(arr, arr + 3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << "First" << endl;
    fillarray();
    ll amt = (arr[1] - arr[0]) + 2 * (arr[2] - arr[1]);
    cout << amt << endl;
    int p;
    cin >> p;
    if(p == 0) return 0;
    else if(p == 1) a += amt;
    else if(p == 2) b += amt;
    else c += amt;
    fillarray();
    if(arr[1] - arr[0] == arr[2] - arr[1]) {
        amt = arr[1] - arr[0];
        cout << amt << endl;
        cin >> p;
        assert(p == 0);
        return 0;
    }
    amt = (arr[1] - arr[0]) + 2 * (arr[2] - arr[1]);
    cout << amt << endl;
    cin >> p;
    if(p == 0) return 0;
    else if(p == 1) a += amt;
    else if(p == 2) b += amt;
    else c += amt;
    fillarray();
    assert(arr[1] - arr[0] == arr[2] - arr[1]);
    amt = arr[1] - arr[0];
    cout << amt << endl;
    cin >> p;
    assert(p == 0);
}