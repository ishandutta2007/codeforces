
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
const int maxn=200005;
int tail[maxn],cnt;
vi g[maxn];
int n,x;

int main()
{
    scan(n);
    cnt=200000;tail[cnt]=0;tail[cnt+1]=1e9+7;
    while(n--)
    {
        scan(x);
        int t=lower_bound(tail+cnt,tail+200002,x)-tail;
        t--;
        if(t==cnt)
        {
            cnt--;
            tail[cnt]=0;
        }
        g[t].pb(x);
        tail[t]=x;
    }
    for(int i=200000;i>cnt;i--)
    {
        int t=0;
        for(int p : g[i])
        {
            t++;
            if(t>1)printf(" ");
            printf("%d",p);
        }
        printf("\n");
    }
    return 0;
}