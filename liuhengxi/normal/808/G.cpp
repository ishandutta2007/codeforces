#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,*f[N],nxt[N][27],fail[N],ans;
char s[N],t[N];
int main()
{
	scanf("%s%s",s,t);
	while(s[n])++n;
	while(t[m])++m;
	F(i,0,n+5)f[i]=new int[m+5];
	F(i,0,n+5)F(j,0,m+5)f[i][j]=-n;
	nxt[0][t[0]-'a']=1;
	F(i,1,m+1)
	{
		F(j,0,26)if(t[i]-'a'==j)fail[nxt[i][j]=i+1]=nxt[fail[i]][j];
		else nxt[i][j]=nxt[fail[i]][j];
	}
	f[0][0]=0;
	F(i,0,n)F(j,0,m+1)
		F(k,0,26)if(s[i]-'a'==k||s[i]=='?')f[i+1][nxt[j][k]]=max(f[i+1][nxt[j][k]],f[i][j]+(nxt[j][k]==m));
	F(j,0,m+1)ans=max(f[n][j],ans);
	printf("%d\n",ans);
	return 0;
}