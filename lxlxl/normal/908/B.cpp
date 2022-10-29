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

const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
const int maxn = 52;

int to[4];
int use[4];

int n,m,len;
int stx,sty;
int edx,edy;
char str[maxn][maxn];

char ss[1100];
int a[1100];

bool judge()
{
	int x=stx,y=sty;
	for(int i=1;i<=len;i++)
	{
		if(x==edx&&y==edy) return true;
		int cc=to[a[i]];
		x+=dx[cc],y+=dy[cc];
		if(x<1||y<1||x>n||y>m||str[x][y]=='#') return false;
	}
	if(x==edx&&y==edy) return true;
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str[i]+1);
		for(int j=1;j<=m;j++)
		{
			if(str[i][j]=='S') stx=i,sty=j;
			else if(str[i][j]=='E') edx=i,edy=j;
		}
	}
	scanf("%s",ss+1); len=strlen(ss+1);
	for(int i=1;i<=len;i++) a[i]=ss[i]-'0';
	
	int ans=0;
	for(int i1=0;i1<4;i1++)
	{
		use[i1]=1; to[0]=i1;
		for(int i2=0;i2<4;i2++) if(!use[i2])
		{
			use[i2]=1; to[1]=i2;
			for(int i3=0;i3<4;i3++) if(!use[i3])
			{
				use[i3]=1; to[2]=i3;
				for(int i4=0;i4<4;i4++) if(!use[i4])
				{
					to[3]=i4;
					if(judge()) ans++;
				}
				use[i3]=0;
			}
			use[i2]=0;
		}
		use[i1]=0;
	}
	printf("%d\n",ans);
	
    return 0;
}