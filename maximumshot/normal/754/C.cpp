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

string buf;

inline bool valid(char const & c) {
    return c >= 'a' && c <= 'z' ||
           c >= 'A' && c <= 'Z' ||
           c >= '0' && c <= '9';
}

void solve() {
    int n;
    cin >> n; getline(cin, buf);
    vec< string > name(n);
    for(int i = 0;i < n;i++) cin >> name[i]; getline(cin, buf);
    int m;
    cin >> m; getline(cin, buf);
    vec< pair< string, string > > mes(m);
    for(int j, i = 0;i < m;i++) {
        getline(cin, buf);
        j = 0;
        while(buf[j] != ':') j++;
        mes[i] = make_pair(
            buf.substr(0, j),
            buf.substr(j + 1)
        );
    }
    vec< vec< char > > dp(m, vec< char >(n));
    for(int i = 0;i < m;i++) {
        if(mes[i].first != "?") {
            int id;
            for(int j = 0;j < n;j++) {
                if(mes[i].first == name[j]) {
                    id = j;
                    break;
                }
            }
            for(int t = 0;t < n;t++) {
                if(id == t) continue;
                dp[i][id] |= (i ? dp[i - 1][t] : 1);
            }
            if(!i) dp[i][id] = 1;
            continue;
        }

        auto & str = mes[i].second;

        vec< char > can(n, 1);

        for(int j = 0;j < (int)str.size();j++) {
            if(!valid(str[j])) continue;
            int t = j;
            string tmp_name = "";
            while(t < (int)str.size() && valid(str[t])) {
                tmp_name.push_back( str[t++] );
            }
            int id = -1;
            for(int q = 0;q < n;q++) {
                if(name[q] == tmp_name) {
                    id = q;
                    break;
                }
            }
            if(id != -1) {
                can[id] = 0;
            }
            j = t - 1;
        }

        for(int j = 0;j < n;j++) {
            if(!can[j]) continue;
            for(int t = 0;t < n;t++) {
                if(t == j) continue;
                dp[i][j] |= (i ? dp[i - 1][t] : 1);
            }
            if(!i) dp[i][j] = 1;
        }
    }

    int cur = -1;

    for(int i = 0;i < n;i++) {
        if(dp[m - 1][i]) {
            cur = i;
            break;
        }
    }

    if(cur == -1) {
        cout << "Impossible\n";
        return;
    }

    for(int i = m - 1;i >= 0;i--) {
        mes[i].first = name[cur];
        for(int j = 0;j < n;j++) {
            if(j == cur) continue;
            if( (i ? dp[i - 1][j] : 1) ) {
                cur = j;
                break;
            }
        }
    }

    for(int i = 0;i < m;i++) {
        cout << mes[i].first << ":" << mes[i].second << "\n";
    }
}

int main() {

    int t;

    cin >> t; getline(cin, buf);

    while(t--) {
        solve();
    }

    return 0;
}