#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lc o << 1
#define rc o << 1 | 1
#define lowbit(x) (x&(-x))
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

const int maxn=100005;

int a[maxn][50],son[maxn][50];
LL sum[maxn][50],mi[maxn][50];
int w[50];
int q;
LL i,j,k,l,m,n;

int main()
{
	scanf("%lld%lld",&n,&m);k=m;
	q=0;while(m>0){w[++q]=m%2;m/=2;}w[q+1]=0;
	memset(mi,0x3f3f3f3f,sizeof(mi));m=k;
	for(i=1;i<=n;i++){int x;scanf("%d",&x);son[i][0]=x+1;}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sum[i][0]=mi[i][0]=k;
	}
	for(j=1,k=2;k<=m;j++,k*=2)
		for(i=1;i<=n;i++)
		{
			son[i][j]=son[son[i][j-1]][j-1];
			sum[i][j]=sum[i][j-1]+sum[son[i][j-1]][j-1];
			mi[i][j]=min(mi[i][j-1],mi[son[i][j-1]][j-1]);
		}
	for(i=1;i<=n;i++)
	{
		LL tot,ans;
		tot=0;ans=0x3f3f3f3f;
		int t,num;
		num=q+1;t=i;
		while(num>0)
		{
			while(w[num]==0 && num>0)num--;
			if(num<=0)break;
			tot+=sum[t][num-1];
			ans=min(ans,mi[t][num-1]);
			t=son[t][num-1];
			num--;
		}
		printf("%lld %lld\n",tot,ans);
	}
    return 0;
}