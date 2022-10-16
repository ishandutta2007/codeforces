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

const int MAX=1e5+5,INF=1e9;

int n,t;double p;
double dp[2005][2005];

void init(void)
{
    cin>>n>>p>>t;
}

void process(void)
{
    dp[0][0]=1;
    for(int i=0;i<t;i++) for(int j=0;j<=i&&j<=n;j++)
    {
        dp[i+1][j+(j<n)]+=p*dp[i][j];
        dp[i+1][j]+=(1-p)*dp[i][j];
    }
    double res=0.0;
    for(int i=0;i<=n;i++) res+=i*dp[t][i];
    cout<<setprecision(10)<<fixed<<res<<endl;
}

int main(void)
{
    init();
    process();
    return 0;
}