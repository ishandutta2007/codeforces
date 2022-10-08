
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

int n, k;

bool ask(int x, int y) {
    cout << "1 " << x << ' ' << y << endl;
    string s;
    cin >> s;
    return s == "TAK";
}

int dish(int L, int R) {
    while(L < R) {
        int x = (L + R) / 2;
        int y = x + 1;
        if(ask(x, y)) {
            R = x;
        }else {
            L = y;
        }
    }
    return L;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int x = dish(1, n);
    int y = (x == 1 ? -1 : dish(1, x - 1));
    int z = (x == n ? -1 : dish(x + 1, n));
    if(y != -1 && ask(y, x)) {
        cout << "2 " << y << ' ' << x << endl;
    }else {
        cout << "2 " << x << ' ' << z << endl;
    }
}