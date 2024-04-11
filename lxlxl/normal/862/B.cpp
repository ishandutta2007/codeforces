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

inline void read(int &x)
{
	char c;
	while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 110000;

int n;
struct edge
{
	int y,nex;
	edge(){}
	edge(const int _y,const int _nex){y=_y;nex=_nex;}
}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=edge(y,fir[x]);fir[x]=len;}

ll ans;
ll s[maxn][2];
int col[maxn];
void dfs(const int x,const int fa)
{
	col[x]=!col[fa];
	for(int k=fir[x];k;k=a[k].nex)
	{
		const int y=a[k].y;
		if(y!=fa) 
		{
			dfs(y,x);
			ans+=s[x][0]*s[y][1]+s[x][1]*s[y][0];
			s[x][0]+=s[y][0];
			s[x][1]+=s[y][1];
		}
	}
	s[x][col[x]]++;
	ans+=s[x][!col[x]];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		ins(x,y); ins(y,x);
	}
	
	col[0]=0;
	dfs(1,0);
	printf("%I64d\n",ans-(ll)(n-1));
	
	return 0;
}