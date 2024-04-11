#include<bits/stdc++.h>
using namespace std;


const int MOD = 1e9 + 7;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}


const int nax = 1024;

string s;
string t;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


void solve() {
    cin >> s >> t;
    vector <int> x = prefix_function(t + '#' + s);
    vector <int> pos;

    for (int i = t.size() + 1, c = 0 ; i < x.size() ; ++ i, ++ c) {
        if (x[i] == t.size()) pos.push_back(c - t.size() + 2);
    }
    int n = s.size();
    vector <pair <int, int>> dp(n, make_pair(5000, 0));
    int m = pos.size();


    auto relax_ans = [](pair <int, int> x1, pair <int, int> x2) -> pair <int, int> {
        if (x2.first > x1.first) return x1;
        if (x1.first == x2.first) return make_pair(x1.first, add(x1.second, x2.second));
        return x2;
    };

    if (m == 0) {
        cout << "0 1\n";
        return;
    }
    dp[0] = make_pair(1, 0);

    for (int i = 0 ; i < m ; ++ i) {
        int to = 0;
        for (int j = 0 ; j < i ; ++ j) {
            if (pos[j] + t.size() - 1 >= pos[i]) continue;
            while (to < i && pos[j] + t.size() - 1 >= pos[to]) to += 1;
            if (((to >= i || pos[to] + t.size() - 1 >= pos[i])) || (pos[j] + t.size() - 1 >= pos[i - 1]))
            dp[i] = relax_ans(dp[i], make_pair(dp[j].first + 1, dp[j].second));
        }
//cout << "? " << j << ' ' << i << '\n';

        if (pos[i] <= pos[0] + t.size() - 1) dp[i] = relax_ans(dp[i], make_pair(1, 1));
        pair <int, int> ans = dp[m - 1];
        if (i == m - 1) {
            for (int j = 0 ; j < i ; ++ j) {
                if (pos[j] + t.size() - 1 >= pos[m - 1]) ans = relax_ans(ans, dp[j]);
            }
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }


}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}