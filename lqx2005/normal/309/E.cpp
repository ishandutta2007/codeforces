#include <bits/stdc++.h>
#define TRACE(x) cerr << #x <<" = " << x << endl
#define _ << " _ " <<
#define sz(a) int((a).size())
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
const int N = 4e3 + 10, oo = 0x3f3f3f3f;
int n, l[N], r[N], arr[N], atot = 0;
int upp[N], num[N], rem[N], pos[N];
vector<int> g[N];
int check(int d) {
    for(int i = 1; i <= n; i++) upp[i] = num[i] = oo, rem[i] = 0;
    vector<int> now;
    int tot = 0;
    for(int i = 1; i <= atot; i++) {
        for(auto v : g[i]) {
            // cout << v << endl;
            if(v > 0) {
                now.push_back(v);
                for(int w = 1; w <= n; w++) if(rem[w]) upp[v] = min(upp[v], num[w] + d);
            } else {
                if(rem[-v]) {
                    rem[-v] = 0;
                    continue;
                }
                while(1) {
                    int pos = -1, est = 0;
                    for(auto w : now) if(w == -v) est = 1;
                    if(!est) break;
                    for(int j = 0; j < sz(now); j++) {
                        if(pos == -1 || r[now[pos]] > r[now[j]]) pos = j;
                        if(tot + j + 1 == upp[now[j]]) break;
                    }
                    int v = now[pos];
                    num[v] = ++tot;
                    rem[v] = 1;
                    // TRACE(v);
                    now.erase(now.begin() + pos);
                    for(auto w : now) upp[w] = min(upp[w], num[v] + d);
                    for(int j = 0; j < sz(now); j++) if(tot + j + 1 > upp[now[j]]) return 0;
                }
                int mn = oo;
                for(int w = 1; w <= n; w++) if(rem[w]) mn = min(mn, num[w]);
                for(auto w : now) upp[w] = min(upp[w], mn + d);
                rem[-v] = 0;
            }
            for(int j = 0; j < sz(now); j++) if(tot + j + 1 > upp[now[j]]) return 0;
        }
    }
    return 1;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i], r[i]++;
        arr[++atot] = l[i], arr[++atot] = r[i];
    }
    sort(arr + 1, arr + atot + 1);
    atot = unique(arr + 1, arr + atot + 1) - (arr + 1);
    for(int i = 1; i <= n; i++) {
        l[i] = lower_bound(arr + 1, arr + atot + 1, l[i]) - arr;
        r[i] = lower_bound(arr + 1, arr + atot + 1, r[i]) - arr;
    }
    for(int i = 1; i <= n; i++) g[r[i]].push_back(-i);
    for(int i = 1; i <= n; i++) g[l[i]].push_back(i);
    int mx = 0, cnt = 0;
    // for(int i = 1; i <= atot; i++) {
    //     for(auto v : g[i]) {
    //         if(v > 0) cnt++;
    //         else cnt--;
    //     }
    //     mx = max(mx, cnt);
    // }
    int l = 0, r = n - 1, d = n + 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) d = mid, r = mid - 1;
        else l = mid + 1;
    }
    check(d);
    for(int i = 1; i <= n; i++) pos[num[i]] = i;
    for(int i = 1; i <= n; i++) cout << pos[i] <<" ";
    cout << endl;
    return 0;
}