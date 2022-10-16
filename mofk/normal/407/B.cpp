#include<bits/stdc++.h>
#define ff(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5,INF=1e9,mod=1e9+7;

int n;
int p[1005];
int dp[1005];

void init(void)
{
    cin>>n;
    ff(i,1,n) cin>>p[i];
}

void process(void)
{
    ff(i,2,n+1) dp[i]=((2*dp[i-1]+2-dp[p[i-1]])%mod+mod)%mod;
    cout<<dp[n+1]<<endl;
}

int main(void)
{
    init();
    process();
    return 0;
}