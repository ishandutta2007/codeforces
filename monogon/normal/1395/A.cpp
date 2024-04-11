
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

bool check(int a, int b, int c, int d) {
    int odd = (a & 1) + (b & 1) + (c & 1) + (d & 1);
    return odd <= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        if(check(r, g, b, w)) {
            cout << "Yes\n";
            goto hell;
        }else if(r > 0 && g > 0 && b > 0) {
            r--; g--; b--; w++;
            if(check(r, g, b, w)) {
                cout << "Yes\n";
                goto hell;
            }
        }
        cout << "No\n";
        hell:;
    }
}