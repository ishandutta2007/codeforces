#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define FOR(i,a,b) for (int i = (a) ; i<= (b); i++)
#define REP(i, n) FOR(i,0,(int)(n) - )
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size()
#define VI vector<int>
#define PII pair<int,int>

const int N = 30005;
const long long INF = 1e18;

int t, n, m, k, l;
char word[200005];
int dp[N];
int cnt[30];

void test() {
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", &word[1]);
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }
    l = strlen(word + 1);
    for (int i = 1; i <= l; i++) {
        cnt[word[i] - 'A']++;
    }
    
    long long ans = INF;
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            dp[j] = 0;
        }
        dp[0] = 1;
        for (int j = 0; j < 26; j++) {
            if (j == i) continue;
            for (int k = n - 1; k >= 0; k--) {
                if (dp[k] == 1 && k + cnt[j] < n) {
                    dp[k + cnt[j]] = 1;
                }
            }
            
            for (int k = 0; k < n; k++) {
                if (dp[k] == 0 || k + cnt[i] < n) continue;
                int used = n - k;
                if (l - (k + cnt[i]) >= m) {
                    ans = 0;
                    break;
                } else {
                    int remaining = m - (l - (k + cnt[i]));
                    ans = min(ans, (long long)used * remaining);
                }
            }
            
        }
    }
    
    printf("%lld\n", ans);
    
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d", &t);
    while (t--) {
        test();
    }
}