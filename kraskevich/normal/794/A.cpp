#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (b < x && x < c)
            res++;
    }
    cout << res << endl;
}