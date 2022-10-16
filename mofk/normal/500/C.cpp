#include<bits/stdc++.h>
#define f(i,n) for(int i=1;i<=n;i++)
#define F(i,n) for(int i=n;i>=1;i--)
#define FF(i,a,b) for(int i=a;i>=b;i--)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define B 1
#define W -1
typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5,INF=1e9;
const ll mod=1e9+7,INFLL=1e18;

int n,m;
int w[505],day[1005],last[505];

void init(void)
{
    cin>>n>>m;
    ff(i,1,n) cin>>w[i];
    ff(i,1,m) cin>>day[i];
}

void process(void)
{
    ll res=0;
    ff(i,1,m)
    {
        int book=day[i];
        int cmp=last[book];
        ff(j,1,n) if(last[j]>cmp) res+=w[j];
        last[book]=i;
    }
    cout<<res<<endl;
}

int main(void)
{
    init();
    process();
    return 0;
}