#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

char A[105][105];

int cost(int i,int j)
{
	if (isdigit(A[i][j]))
		return A[i][j]-'0';
	return 1;
}

int dx[30][105][105]={0};
int dy[30][105][105]={0};

int DX[4]={0,0,-1,1};
int DY[4]={-1,1,0,0};
void go(int ind,int x,int y)
{
	int stx=x,sty=y;
	bool was[105][105]={0};
	queue<pii> q;
	was[x][y]=1;
	q.push(pii(x,y));
	while (!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if (!isdigit(A[x][y]) && (x!=stx || y!=sty))
			continue;
		rep(k,0,4)
		{
			int nx=x+DX[k];
			int ny=y+DY[k];
			if (A[nx][ny]!='#' && !was[nx][ny])
			{
				was[nx][ny]=1;
				q.push(pii(nx,ny));
				dx[ind][nx][ny]=x-nx;
				dy[ind][nx][ny]=y-ny;
			}
		}
	}
}

void run()
{
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,1,n+1)
		scanf("%s",A[i]+1);
	pii P[300];
	rep(i,1,n+1)
		rep(j,1,m+1)
			if (A[i][j]>='a' && A[i][j]<='z')
				P[A[i][j]]=pii(i,j);
	rep(i,0,n+2)
		A[i][0]=A[i][m+1]='#';
	rep(j,0,m+2)
		A[0][j]=A[n+1][j]='#';
	rep(i,'a','z'+1)
		if (P[i].first!=0)
			go(i-'a',P[i].first,P[i].second);
	int x,y;
	scanf("%d%d",&x,&y);
	char str[1010];
	scanf("%s",str);
	int fx,fy;
	scanf("%d%d",&fx,&fy);
	go(28,fx,fy);
	int pos=0;
	int ind=str[pos]-'a';
	int len=strlen(str);
	int di=dx[ind][x][y];
	int dj=dy[ind][x][y];
	while (1)
	{
		if (pos==len && x==fx && y==fy)
			break;
		if (A[x][y]>='a' && A[x][y]<='z')
		{
			pos++;
			if (pos==len)
				ind=28;
			else
				ind=str[pos]-'a';
		}
		di=dx[ind][x][y];
		dj=dy[ind][x][y];
		if (k<cost(x,y))
			break;
		k-=cost(x,y);
		x+=di;
		y+=dj;
	}
	printf("%d %d\n",x,y);

}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*

*/