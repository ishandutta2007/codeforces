#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=50005;
int n,ans,a[N][5];
inline bool cmp(int x,int y)
{
	int s=0;
	rep(i,0,4)if(a[x][i]<a[y][i])s++;
	return s>=3;
}
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();ans=1;
		rep(i,1,n)rep(j,0,4)a[i][j]=rd();
		rep(i,2,n)if(!cmp(ans,i))ans=i;
		rep(i,1,n)if(ans!=i&&!cmp(ans,i)){ans=-1;break;}
		printf("%d\n",ans);
	}
	return 0;
}