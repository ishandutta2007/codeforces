#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll, ll>
typedef long long ll;
int Abs(int x) {
    return x>0?x:-x;
}

ll n;

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        string s;
        cin >> s;
        if (x > 2) {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " ";
            for (int i = 1; i < x; i++)
                cout << s[i];
            cout << endl;
        } else {
            if (s[0] < s[1]) {
                cout << "YES" << endl;
                cout << 2 << endl;
                cout << s[0] << " " << s[1] << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}