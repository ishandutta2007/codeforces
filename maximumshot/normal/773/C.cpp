#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;
int const LOG = 60;

int n;
ll a[N];
int res[N];
int sz = 0;
int cnt[LOG];
int tot[LOG];
int mn[N];
int ost[LOG];
int tmp[LOG];
int have[LOG];
int need[LOG];

int main() {

    ios_base::sync_with_stdio(0);

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        for(int j = LOG - 1;j >= 0;j--) {
            if((1ll << j) >= a[i]) {
                mn[i] = j;
            }
        }
        tmp[mn[i]]++;
        if((1ll << mn[i]) == a[i]) {
            tot[mn[i]]++;
        }
    }

//    for(int j = 0;j <= 4;j++) {
//        cout << tmp[j] << " ";
//    }
//    cout << " | ";
//    for(int j = 0;j <= 4;j++) {
//        cout << tot[j] << " ";
//    }
//    cout << "\n";

    for(int l = 1;l <= n && l <= tmp[0];l++) {
        for(int j = 0;j < LOG;j++) {
            cnt[j] = min(l, tot[j]);
            if(j > 0) cnt[j] = min(cnt[j], cnt[j - 1]);
            need[j] = tmp[j] - cnt[j];
        }
        for(int j = 0;j < LOG;j++) {
            have[j] = 0;
        }
        have[0] = l;
        for(int pref = 0, j = LOG - 2;j >= 0;j--) {
            have[j + 1] = cnt[j] - pref;
            pref += have[j + 1];
            have[0] -= have[j + 1];
        }
        int have_id = LOG - 1;
        int need_id = LOG - 1;
        int ok = 1;
//        for(int j = 0;j <= 4;j++) {
//            cout << have[j] << " ";
//        }
//        cout << " | ";
//        for(int j = 0;j <= 4;j++) {
//            cout << need[j] << "\n";
//        }
        while(have_id >= 0 && need_id >= 0) {
            while(have_id >= 0 && have[have_id] == 0) have_id--;
            while(need_id >= 0 && need[need_id] == 0) need_id--;
            if(need_id < 0) break;
            if(have_id < 0) {
                ok = 0;
                break;
            }
            if(have_id < need_id) {
                ok = 0;
                break;
            }
            int T = min(have[have_id], need[need_id]);
            have[have_id] -= T;
            need[need_id] -= T;
        }
        if(ok) {
            res[sz++] = l;
        }
    }

    if(sz == 0) {
        cout << "-1\n";
    }else {
        for(int i = 0;i < sz;i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}