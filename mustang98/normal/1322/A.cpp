#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

int st[max_n];
int fn[max_n];
vector<int> o, c;
int n;
char s[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            o.PB(i);
        } else {
            c.PB(i);
        }
    }
    if (o.size() != c.size()) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (c[i] < o[i]) {
            st[c[i]]++;
            fn[o[i]]++;
        }
    }
    int ans = 0;
    int bal = 0;
    for (int i = 0; i < n; ++i) {
        bal += st[i];
        if (bal > 0) {
            ++ans;
        }
        bal -= fn[i];
    }
    cout << ans << endl;
    return 0;
}