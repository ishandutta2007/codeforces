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
int a[maxn],pos[30];
int st[maxn][20],lo[maxn];
int n,l,r;
pii c[30];
LL ans=0;
int find(int x,int y){
    int u=lo[y-x+1];
    return max(st[x][u],st[y-(1<<u)+1][u]);
}
int main(){   
    lo[1]=0;for(int i=2;i<=200000;i++)lo[i]=lo[i>>1]+1;
    scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)st[i][0]=a[i];
    for(int mask=1;(1<<mask)<=n;mask++)
        for(int i=1;i+(1<<mask)-1<=n;i++)
            st[i][mask]=max(st[i][mask-1],st[i+(1<<(mask-1))][mask-1]);
    for(int i=1;i<=n;i++){
        for(int j=0;j<30;j++)
            if((a[i]>>j)&1)pos[j]=i;
        for(int j=0;j<30;j++)c[j]=mp(pos[j],j);
        sort(c,c+30);int now=0;
        for(int j=29;j>=0;j--){
            if(c[j].fi<=0)break;
            now|=1<<c[j].se;
            l=(j==0?1:c[j-1].fi+1);r=c[j].fi;
            if(l>r)continue;
            if(find(l,r)<now){ans+=1ll*(r-l+1);continue;}
            while(r-l>1){
                int mid=(l+r)>>1;
                if(find(mid,i)<now)r=mid;else l=mid;
            }
            if(find(l+1,i)>=now)l++;
            if(l<c[j].fi)ans+=1ll*(c[j].fi-l);
        }}
    printf("%lld\n",ans);return 0;
}