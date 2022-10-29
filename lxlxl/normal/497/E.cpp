#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 5100;
const int Mod = 1000000007;
const int maxk = 33;

ll n; int K;
int t[maxn],pt[maxn],tp;
struct mat{int a[maxk][maxk];mat(){memset(a,0,sizeof a);}}trans[maxk],M[maxn],one;
mat operator *(const mat &x,const mat &y)
{
	mat re;
	for(int i=0;i<=K+1;i++) for(int j=0;j<=K+1;j++)
		for(int k=0;k<=K+1;k++) re.a[i][k]=(re.a[i][k]+(ll)x.a[i][j]*y.a[j][k]%Mod)%Mod;
	return re;
}

struct trie{int son[maxk];}tr[maxn]; int root,cnt;
mat pre[maxn],suf[maxn];
void dp(const int x,const int y,const int dep)
{
	for(int i=0;i<K;i++) tr[x].son[i]=++cnt;
	if(dep==0)
	{
		dp(tr[x].son[0],tr[y].son[t[1]],dep+1);
		M[x]=M[tr[x].son[0]];
		for(int i=1;i<t[1];i++)
		{
			int p=tr[x].son[i];
			M[p]=suf[i]*pre[i-1];
			M[x]=M[x]*M[p];
		}
		M[x]=M[x]*M[tr[y].son[t[1]]];
		return;
	}
	for(int i=0;i<K;i++) tr[y].son[i]=++cnt;
	if(dep==tp-1)
	{
		for(int i=0;i<K;i++) M[tr[x].son[i]]=trans[i];
		pre[0]=M[tr[x].son[0]];
		for(int i=1;i<K;i++) pre[i]=pre[i-1]*M[tr[x].son[i]];
		suf[K]=one;
		for(int i=K-1;i>=0;i--) suf[i]=M[tr[x].son[i]]*suf[i+1];
		M[x]=pre[K-1];
		
		M[y]=one;
		for(int i=0;i<=t[tp];i++)
			M[y]=M[y]*trans[(pt[dep]+i)%K];
		return;
	}
	dp(tr[x].son[0],tr[y].son[t[dep+1]],dep+1);
	for(int i=1;i<K;i++) M[tr[x].son[i]]=suf[i]*pre[i-1];
	pre[0]=M[tr[x].son[0]];
	for(int i=1;i<K;i++) pre[i]=pre[i-1]*M[tr[x].son[i]];
	suf[K]=one;
	for(int i=K-1;i>=0;i--) suf[i]=M[tr[x].son[i]]*suf[i+1];
	
	M[y]=one;
	for(int i=0;i<t[dep+1];i++)
	{
		int cc=(pt[dep]+i)%K;
		M[y]=M[y]*M[tr[x].son[cc]];
	}
	M[x]=pre[K-1];
	M[y]=M[y]*M[tr[y].son[t[dep+1]]];
}

int main()
{
	scanf("%I64d%d",&n,&K); --n;
	for(int i=0;i<K;i++)
	{
		int x=i+1;
		trans[i].a[0][0]=1,trans[i].a[0][x]=1;
		for(int j=0;j<K;j++) if(i!=j)
		{
			int y=j+1;
			trans[i].a[y][0]=1;
			trans[i].a[y][y]=1;
		}
		trans[i].a[K+1][K+1]=1;
		trans[i].a[K+1][0]=1;
	}
	for(int i=0;i<=K+1;i++) one.a[i][i]=1;
	
	for(ll now=n;now;now/=K) t[++tp]=now%K;
	for(int j=1;j*2<=tp;j++) swap(t[j],t[tp-j+1]);
	for(int j=1;j<=tp;j++) pt[j]=(pt[j-1]+t[j])%K;
	
	root=cnt=1;
	if(n<K) return printf("%d\n",(1<<n+1)%Mod),0;
	dp(root,root,0);
	mat re; re.a[0][0]=1; re.a[0][K+1]=1;
	re=re*M[1];
	printf("%d\n",re.a[0][0]);
	
	return 0;
}