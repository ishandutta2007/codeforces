#include <bits/stdc++.h>
using namespace std;

int a[100010],b[100010],n,c[100010];

pair <int,int> p[100010],q[100010];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 0; i < n; ++i) {
            c[i] = 0;
        }
        for(int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        for(int i = 0; i < n; ++i) {
            cin>>b[i];
        }
        for(int i = 0; i < n; ++i) {
            p[i] = make_pair(a[i], b[i]);
            q[i] = make_pair(b[i], a[i]);
        }
        sort(p, p+n);
        sort(q, q+n);
        int x1 = n - 1, y2 = p[n - 1].second;
        int x2 = n - 1, y1 = q[n - 1].second;
        while((p[x1].first > y1 || q[x2].first > y2) && x1 > 0 && x2 > 0) {
            int z1 = y1, z2 = y2;
            while(x1 > 0 && p[x1].first > y1) {
                z2 = min(z2, p[x1].second);
                x1--;
            }
            if (x1 <= 0) break;
            while(x2 > 0 && q[x2].first > y2) {
                x2--;
                z1 = min(z1, q[x2].second);
            }
            if (x2 <= 0) break;
            y1 = z1;
            y2 = z2;
        }
        for(int i = 0; i < n; ++i) {
            if (lower_bound(p, p + n, make_pair(a[i], b[i])) - p >= x1) c[i] = 1;
            if (lower_bound(q, q + n, make_pair(b[i], a[i])) - q >= x2) c[i] = 1;
            cout<<c[i];
        }
        cout<<endl;
    }
    return 0;
}