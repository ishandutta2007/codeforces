#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;

int n, a[maxn], b[maxn], ar[2*maxn], rev[2*maxn];
map<int, int> mp; int cnt;

int bit[4*maxn], tot;

int qry(int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

void upd(int i, int v) {
    tot += v;
    for (i++; i<4*maxn; i+=i&-i) bit[i] += v;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        mp[a[i]] = mp[b[i]] = 0;
    }
    
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        it->second = cnt;
        ar[cnt] = rev[cnt] = it->first;
        cnt++;
    }
    
    for (int i=0; i<n; i++) swap(mp[a[i]], mp[b[i]]);
    long long ans = 0;
    for (int i=0; i<cnt; i++) {
        if (i>0) ans += 1LL * (rev[i]-rev[i-1]-1) * (tot-qry(i-1));
        upd(i, rev[i]-(i==0 ? rev[i] : rev[i-1]+1));
        ans += tot-qry(mp[ar[i]]);
        upd(mp[ar[i]], 1);
    }
    cout << ans;
}