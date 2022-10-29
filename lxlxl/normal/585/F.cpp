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

const int maxp = 110000;
const int maxn = 1100;
const ll Mod = 1e9+7;

struct trie
{
	int son[10],fail;
}tr[maxp]; int root,tot;
bool v[maxp];
void ins(char s[],const int l,const int r)
{
	int x=root;
	for(int i=l;i<r;i++)
	{
		const int w=s[i]-'0';
		int &y=tr[x].son[w];
		if(!y) y=++tot;
		x=y;
	}
	v[x]=true;
}
char str[maxn]; int n,d;
queue<int>q;
void build()
{
	n=strlen(str); int D=d/2;
	root=tot=0;
	for(int i=0;i+D-1<n;i++) ins(str,i,i+D);
	q.push(root);
	while(!q.empty())
	{
		const int x=q.front(); q.pop();
		if(v[x]) for(int i=0;i<10;i++) tr[x].son[i]=x;
		else
		{
			for(int i=0;i<10;i++)
			{
				int &y=tr[x].son[i],fl=tr[x].fail;
				if(y) 
				{
					if(x!=root) tr[y].fail=tr[fl].son[i];
					q.push(y);
				}
				else y=tr[fl].son[i];
			}
		}
	}
}

char A[maxn],B[maxn];
//  rol 0 up
ll f[2][2][2][maxp];
ll cal(char s[])
{
	int now=0; 
	memset(f,0,sizeof f); f[now][1][1][0]=1;
	for(int p=0;p<d;p++)
	{
		now=!now;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++)
		{
			for(int x=0;x<=tot;x++) if(f[!now][i][j][x])
			{
				ll tmp=f[!now][i][j][x]%Mod; f[!now][i][j][x]=0;
				int uk=j?s[p]-'0':9;
				for(int k=0;k<=uk;k++)
				{
					int ni=i&(k>0?0:1),nj=j&(k==uk?1:0),y=(!k&&i)?0:tr[x].son[k];
					f[now][ni][nj][y]+=tmp;
				}
			}
		}
	}
	ll re=0;
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int x=0;x<=tot;x++) if(v[x]&&f[now][i][j][x])
		(re+=f[now][i][j][x]%Mod)%=Mod;
	return re;
}

int t[maxn],tp;
bool judge(int x)
{
	int tp=0; while(x) t[++tp]=x%10,x/=10;
	x=root;
	for(int i=tp;i>=1;i--) x=tr[x].son[t[i]];
	return v[x];
}

int main()
{
	scanf("%s",str);
	scanf("%s%s",A,B); d=strlen(A);
	build();
	
	ll ans=cal(B)-cal(A);
	int x=root;
	for(int i=0;i<d;i++) x=tr[x].son[A[i]-'0'];
	if(v[x]) ans++;
	ans=(ans+Mod)%Mod;
	printf("%I64d\n",ans);
	
	return 0;
}