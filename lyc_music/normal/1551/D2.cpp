//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define y1 nmsl
#define il inline
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 1000000007
#define Endl endl
//#define int ll
#define N 2005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,k;
char A[N][N];
signed main()
{
	T=read();
	while (T--)
	{
		n=read(),m=read(),k=read();int kkk=k;
			int ans=1;
			for (int i=1;i<=n;i++)	for (int j=1;j<=m;j++) A[i][j]='*';
			if (m%2==0&&n%2==1)
			{
				if (k<m/2) ans=0;
				else
				{
					k-=m/2;
					if (k%2==1) ans=0;
					else ans=1;
				}	
				if (ans) 
				{
					puts("YES");
					k=kkk;
					for (int i=1;i<=m/2;i++)
					{
						A[n][i*2-1]=A[n][i*2]='a'+(i%2);
						k--;
					}
					for (int i=1;i<=m/2;i++)
					{
						if (!k) break;
						for (int j=n-1;j>=1;j--)
						{
							if (!k) break;
							A[j][2*i-1]=A[j][2*i]=(A[j+1][2*i]=='a')?'b':'a';
							k--;
						}
					}
					if (n>1)
					{
						int i=1;
						for (int j=1;j<=m;j++)
						{
							if (A[i][j]=='*')
							{
								A[i][j]=A[i+1][j]='c'+j%2;
							}
						}
						for (int i=3;i<n;i+=2)
						{
							for (int j=1;j<=m;j++)
							{
								if (A[i][j]=='*')
								{
									A[i][j]=A[i+1][j]=(A[i-1][j]=='c')?'d':'c';
								}
							}
						}
					}
					for (int i=1;i<=n;i++)
					{
						for (int j=1;j<=m;j++) cout<<A[i][j];
						puts("");
					}
				}
				else puts("NO");
			} else
			{
				
				for (int i=1;i<=m/2;i++)
				{
					if (k<n)
					{
						if ((n-k)%2==1) ans=0;
						else ans=1;
						k=0;
						break;
					}
					k-=n;
				}
				if (k!=0) ans=0;
				if (ans) 
				{
					puts("YES");
					k=kkk;
					for (int i=1;i<=m/2;i++)
					{
						if (!k) break;
						A[n][2*i-1]=A[n][2*i]=(A[n][2*i-2]=='a')?'b':'a';
						k--;
						for (int j=n-1;j>=1;j--)
						{
							if (!k) break;
							A[j][2*i-1]=A[j][2*i]=(A[j+1][2*i]=='a')?'b':'a';
							k--;
						}
					}
					if (n>1)
					{
						int i=1;
						for (int j=1;j<=m;j++)
						{
							if (A[i][j]=='*')
							{
								A[i][j]=A[i+1][j]='c'+j%2;
							}
						}
						for (int i=3;i<n;i+=2)
						{
							for (int j=1;j<=m;j++)
							{
								if (A[i][j]=='*')
								{
									A[i][j]=A[i+1][j]=(A[i-1][j]=='c')?'d':'c';
								}
							}
						}
					}
					for (int i=1;i<=n;i++)
					{
						for (int j=1;j<=m;j++) cout<<A[i][j];
						puts("");
					}
				} else puts("NO");
			}
	}
}
/*

*/