
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
int n,a,b,k,f,cnt=0;
map< pair< string , string > , int > m;
int cost[1005];
string last="";

int main()
{
    cin>>n>>a>>b>>k>>f;
    while(n--)
    {
        string x,y;
        cin>>x>>y;
        pair<string,string> t=mp(x,y);
        if(m[t]==0)
        {
            m[t]=++cnt;
            m[mp(y,x)]=cnt;
        }
        if(x==last)cost[m[t]]+=b;else cost[m[t]]+=a;
        last=y;
    }
    int ans=0;
    for(int i=1;i<=cnt;i++)ans+=cost[i];
    sort(cost+1,cost+cnt+1);
    for(int i=cnt;i>=max(1,cnt-k+1);i--)
    {
        if(cost[i]<=f)break;
        ans-=cost[i]-f;
    }
    printf("%d\n",ans);
    return 0;
}