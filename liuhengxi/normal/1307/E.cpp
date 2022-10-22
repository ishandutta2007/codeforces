#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005,MOD=1000000007;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int n,m,s[N][N],p[N][N],mx,cnt;
void solve()
{
	int ans=0,c=1;
	F(i,0,n)if(p[i][s[n][i]]>=1)ans+=1,c=int(c*(long long)p[i][s[n][i]]%MOD);
	if(ans>mx)mx=ans,cnt=0;
	if(ans==mx)reduce(cnt+=c);
}
void solve(int x)
{
	int ans=0,c=1;
	F(i,0,n)if(s[x][i]==s[x+1][i])
	{
		int lcnt=s[x+1][i],rcnt=s[n][i]-lcnt;
		int a=lcnt<rcnt?lcnt:rcnt,b=lcnt^rcnt^a;
		if(p[i][a]>=1&&p[i][b]>=2)ans+=2,c=int(p[i][a]*(p[i][b]-1ll)*c%MOD);
		else if(p[i][b]>=1)ans+=1,c=int(c*(long long)(p[i][a]+p[i][b])%MOD);
	}
	else
	{
		int lcnt=s[x+1][i],rcnt=s[n][i]-s[x+1][i];
		if(p[i][lcnt-1]==p[i][lcnt])c=0;
		else 
		{
			long long r=p[i][rcnt]-(lcnt<=rcnt);
			if(r)c=int(c*r%MOD),ans+=2;
			else ++ans;
		}
	}
	if(ans>mx)mx=ans,cnt=0;
	if(ans==mx)reduce(cnt+=c);
}
int main()
{
	read(n,m);
	F(i,0,n)
	{
		int x;
		F(j,0,n)s[i+1][j]=s[i][j];
		++s[i+1][--read(x)];
	}
	F(i,0,m){int f,h;read(f,h);++p[--f][h];}
	F(i,0,n)F(j,0,n)p[i][j+1]+=p[i][j];
	solve();
	F(i,0,n)solve(i);
	printf("%d %d\n",mx,cnt);
	return 0;
}