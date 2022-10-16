#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int INF = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 100;
const int64 MOD = 1000000007;

int64 dp[MAXN];
int64 acc[MAXN];

int main()
{
    int N,v;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> v;
        acc[v]++;
    }
    dp[1] = acc[1];
    for (int64 i = 2; i < MAXN; ++i)
    {
        dp[i] = max(i * acc[i] + dp[i - 2], dp[i - 1]);
    }
    cout << dp[MAXN - 1] << endl;
}