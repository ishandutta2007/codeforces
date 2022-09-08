#include <bits/stdc++.h>
#define int long long
using namespace std;

vector <int> sooke1, sooke2;

int n, m;

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(false);
    cin . tie(0);
    cin >> n >> m;
    int maxn = sqrt((n + m) * 2 + 0.25) - 0.5;
    for(register int i = maxn; i >= 1; i--) {
        if(n >= i) n -= i, sooke1.push_back(i);
        else if(m >= i) m -= i, sooke2.push_back(i);
    }
    cout << sooke1.size() << endl;
    for(auto it = sooke1.begin(); it != sooke1.end(); it++) cout << *it << " "; cout << endl;
    cout << sooke2.size() << endl;
    for(auto it = sooke2.begin(); it != sooke2.end(); it++) cout << *it << " "; cout << endl;
    return 0;
}