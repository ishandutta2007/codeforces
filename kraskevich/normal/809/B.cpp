#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

bool ask(int a, int b) {
    cout << 1 << " " << a << " " << b << endl;
    string s;
    cin >> s;
    return s[0] == 'T';
}

int go(int l, int r) {
    if (l > r)
        return -1;
    if (l == r)
        return l;
    int m = (l + r) / 2;
    if (ask(m, m + 1))
        return go(l, m);
    return go(m + 1, r);
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int foo, n;
    cin >> n >> foo;
    int a = go(1, n);
    int b = go(1, a - 1);
    if (b == -1 || !ask(b, a))
        b = go(a + 1, n);
    cout << 2 << " " << a << " " << b << endl;
}