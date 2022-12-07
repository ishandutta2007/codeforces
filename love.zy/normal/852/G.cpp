#include<bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (1000000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %I64d\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
#define MAXNode (100000*50+10)
#define Sigma_size (5)
int vis_t=0;
class Trie
{
public:
	int vis[MAXNode];
	int ch[MAXNode][Sigma_size];
	int v[MAXNode],siz;
	Trie(int _siz=0):siz(_siz){MEM(ch) MEM(v)}
	void mem(int _siz=0){siz=_siz; MEM(ch) MEM(v) MEM(vis)	}
	int idx(char c){return c-'a';}
	void insert(char *s,int val=0)
	{
		int u=0,n=strlen(s);
		Rep(i,n)
		{
			int c=idx(s[i]);
			if (!ch[u][c])
			{
				++siz;
				MEM(ch[siz]);
				ch[u][c]=siz;
			}
			u=ch[u][c];
		}
		v[u]+=val;
	}
	int find(int u,char *s)
	{
//		cout<<u<<endl;
		int n=strlen(s);
		Rep(i,n)
		{
			if (s[i]=='?') {
				int tot=find(u,s+i+1);
				Rep(c,5)if (ch[u][c]) {
//					cout<<i<<';';
					tot+=find(ch[u][c],s+i+1);
				}
//				cout<<tot<<endl;
				return tot;
			}
			int c=idx(s[i]);
			if (!ch[u][c])
			{
				return 0;
			}
			u=ch[u][c];
		}
		if (vis[u]==vis_t) return 0;
		vis[u]=vis_t;
//		cout<<u<<v[u]<<endl;
		return v[u];
	}
}T;
char s[123456];
int main()
{
//	freopen("g.in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m=read();
	T.mem();
	For(i,n) {
		scanf("%s",s);
		T.insert(s,1);
	}
	For(i,m) {
		vis_t++;
		scanf("%s",s);
		printf("%d\n",T.find(0,s));
	}
	
	return 0;
}