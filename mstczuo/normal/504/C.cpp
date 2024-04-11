# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

int cnt[100010];
int a[100010];

int get_ans(int a[],int n) {
    int midP = (n&1) ? n/2 : -1; 
    int halfP = n/2 - 1;
    int ans = 0;
    int k;
    for(int i = 0; i < n; ++i) {
        if(i <= halfP) k = 2;
        else if(i == midP) k = 1;
        else k = 0;
        if(k == 0) {
            if(a[n-1-i]!=a[i]) k = n;
        }

        if(cnt[a[i]] >= k) {
            ans += 1;
            cnt[a[i]] -= k;
        } else break;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int l, r;
    for(l = 0, r = n; l < r; ++l,--r)
        if(a[l] != a[r-1]) break;
    if(l > r || l==r || l+1==r) {
        cout << 1ll * n * (n+1) / 2 << endl;
        return 0;
    }
    memset(cnt, 0, sizeof(cnt));
    for(int i = l; i < r; ++i) cnt[a[i]] += 1;
    int count_odd = 0;
    for(int i = 1; i <= n; ++i)
        if(cnt[i] & 1) count_odd += 1;
    if(count_odd > 1) {
        puts("0"); return 0;
    }
    int ansk = l + 1;
    memset(cnt, 0, sizeof(cnt));
    for(int i = l; i < r; ++i) cnt[a[i]] += 1;
    int ansl = get_ans(a+l,r-l);
    reverse(a + l, a + r);
    memset(cnt, 0, sizeof(cnt));
    for(int i = l; i < r; ++i) cnt[a[i]] += 1;
    int ansr = get_ans(a+l,r-l);
    long long ans = 1ll*ansl*ansk+1ll*ansr*ansk+1ll*ansk*ansk;
    cout<<ans<<endl;
    return 0;
}