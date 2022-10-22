#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;
int const M = 100005;
int const P = 105;

int n, m, p;
ll d[N], value[M], sumvalue[M];
ll dp[M], dp2[M];

bool solve() {

    scanf("%d %d %d", &n, &m, &p);

    p = min(p, m);

    for(int x, i = 2;i <= n;i++) {
        scanf("%d", &x);
        d[i] = d[i - 1] + x;
    }

    for(int H, T, i = 0;i < m;i++) {
        scanf("%d %d", &H, &T);
        value[i] = T - d[H];
    }

    sort(value, value + m);

    sumvalue[0] = value[0];
    for(int i = 1;i < m;i++) sumvalue[i] = sumvalue[i - 1] + value[i];

    for(int i = 0;i < m;i++) {
        dp[i] = value[i] * (i + 1) - sumvalue[i];
    }

    for(int cn = 2;cn <= p;cn++) {
        for(int i = 0;i < m;i++) {
            dp2[i] = dp[i];
            dp[i] = inf64;
        }
        vec< pair< ll, ll > > st;
        pair< ll, ll > l1, l2, l3;

        st.push_back({-(cn - 2), dp2[cn - 2] + sumvalue[cn - 2]});

        for(int j = 0, i = cn - 1;i < m;i++) {
            ll add = value[i] * i - sumvalue[i];
            j = min(j, (int)st.size() - 1);
            while(j + 1 < (int)st.size() &&
                  st[j].first * value[i] + st[j].second >= st[j + 1].first * value[i] + st[j + 1].second) {
                j++;
            }
            dp[i] = st[j].first * value[i] + st[j].second + add;
            l3 = {-i, dp2[i] + sumvalue[i]};
            while((int)st.size() >= 2) {
                l1 = st[(int)st.size() - 2];
                l2 = st[(int)st.size() - 1];
                if(1.0 * (l1.second - l2.second) / (l2.first - l1.first) < 1.0 * (l2.second - l3.second) / (l3.first - l2.first))
                    break;
                else
                    st.pop_back();
            }
            st.push_back(l3);
        }
    }

    cout << dp[m - 1] << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}