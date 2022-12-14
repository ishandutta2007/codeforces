#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define Rep(i,x) for(int i=head[x];i+1;i=nxt[i])
#define rep2(i,a,b) for(int i=(a);i<(b);i++)
#define ff first
#define ss second
using namespace std;
const int N=200005;
const int inf=1e9+7;
typedef long long ll;
//------------------------------------------head---------------------------------------------------//
inline int ab(int x){return x<0 ? -x : x;}
int main()
{
	int n,m,a,b;scanf("%d%d%d%d",&n,&m,&a,&b);
	int dif=ab(a-n)+ab(m-b)+2;
	if(n==a)dif++;if(m==b)dif++;dif<<=1;
	printf("%d\n",dif);
	return 0;
}