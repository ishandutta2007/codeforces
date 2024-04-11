#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;

    cin >> n;

    vec< int > a(n);

    ll Sum = 0;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        Sum += a[i];
    }

    int m;

    cin >> m;

    vec< int > b(m);

    for(int i = 0;i < m;i++) {
        cin >> b[i];
        Sum -= b[i];
    }

    if(Sum != 0) {
        cout << "NO\n";
        return true;
    }

    vec< pii > res;

    for(int j = 0, i = 0;i < m;i++) {
        ll cur_sum = 0;
        int last = j;
        while(j < n && cur_sum < b[i]) {
            cur_sum += a[j++];
        }
        if(cur_sum != b[i]) {
            cout << "NO\n";
            return true;
        }
        res.push_back({last, j - 1});
    }

    vec< pair< int, char > > way;

    vec< char > live(n, 1);

    for(int i = 0;i < (int)res.size();i++) {
        int mx = -1, cnt = 0, id = -1, mn = inf;
        int ql, qr;
        tie(ql, qr) = res[i];
        for(int j = ql;j <= qr;j++) {
            if(a[j] > mx) {
                mx = a[j];
                cnt = 1;
                id = j;
            }else if(a[j] == mx) {
                cnt++;
            }
            if(a[j] < mn) {
                mn = a[j];
            }
        }
        if(cnt != 1) {
            if(mx == mn) {
                cout << "NO\n";
                return true;
            }else {
                for(int j = ql;j <= qr;j++) {
                    if(a[j] == mx) {
                        if(j > ql && a[j - 1] < a[j]) {
                            //cout << j << " L !! : ";
                            id = j;
                            int cur_id = 1;
                            for(int iter = 0;iter < id;iter++) cur_id += live[iter];
                            //for(int x : live) cout << x << " ";
                            //cout << " | ";
                            //cout << cur_id << "\n";
                            way.push_back({cur_id, 'L'});
                            live[j - 1] = 0;
                            break;
                        }
                        if(j < qr && a[j + 1] < a[j]) {
                            id = j;
                            int cur_id = 1;
                            //cout << j << " R !!\n";
                            for(int iter = 0;iter < id;iter++) cur_id += live[iter];
                            way.push_back({cur_id, 'R'});
                            live[j + 1] = 0;
                            break;
                        }
                    }
                }
            }
        }
        for(int j = ql;j < id;j++) {
            if(!live[j]) continue;
            int cur_id = 1;
            for(int iter = 0;iter < id;iter++) cur_id += live[iter];
            way.push_back({cur_id, 'L'});
            live[j] = 0;
        }
        for(int j = id + 1;j <= qr;j++) {
            if(!live[j]) continue;
            int cur_id = 1;
            for(int iter = 0;iter < id;iter++) cur_id += live[iter];
            way.push_back({cur_id, 'R'});
            live[j] = 0;
        }
    }

    cout << "YES\n";

    for(auto iter : way) {
        cout << iter.first << " " << iter.second << "\n";
    }

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}