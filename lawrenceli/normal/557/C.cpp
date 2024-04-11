#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int maxn = 100100;
const int maxd = 205;

int n;
piii ar[maxn]; 
int num[maxd], p[maxn];

bool cmp(piii p1, piii p2) {
    return p1.fi.se < p2.fi.se;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> ar[i].fi.fi;
    for (int i=0; i<n; i++) cin >> ar[i].fi.se;
    for (int i=0; i<n; i++) {
        ar[i].se = i;
    }
    sort(ar, ar+n);
    for (int i=0; i<n; i++) {
        p[i+1] = p[i] + ar[i].fi.se;
    }
    
    int ans = 1e9;

    for (int i=0, j=0; i<n; i=j) {
        for (j=i; j<n && ar[j].fi.fi == ar[i].fi.fi; j++);
        int s = p[n]-p[j];
        int r = max(0, n+1-2*(j-i)-(n-j));
        for (int k=0; k<maxd && r; k++) {
            int x = min(num[k], r);
            s += x*k;
            r -= x;
        }
        for (int k=i; k<j; k++) num[ar[k].fi.se]++;

//        cout << i << ' ' << j << ' ' << s << endl;
        ans = min(ans, s);
    }
    cout << ans << '\n';
}