#pragma comment(linker,"/STACK:650000000")
#include <iostream>
#include <cstdio>
#include <bitset>
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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <assert.h>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

char A[1010][1010];

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int D[1010][1010];
void bfs(int x,int y,int n,int m)
{
	queue<pii> q;
	q.push(pii(x,y));
	memset(D,-1,sizeof(D));
	D[x][y] = 0;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		rep(k,0,4)
		{
			int nx = x+dx[k];
			int ny = y+dy[k];
			if (nx>=0 && nx<n && ny>=0 && ny<m && D[nx][ny]==-1 && A[nx][ny]!='T')
			{
				D[nx][ny] = D[x][y]+1;
				q.push(pii(nx,ny));
			}
		}
	}
}

void run()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,n)
		scanf("%s",A[i]);
	int ex,ey;
	int sx,sy;
	rep(i,0,n)
		rep(j,0,m)
		if (A[i][j]=='E')
		{
			ex=i;
			ey=j;
		}
		else if (A[i][j]=='S')
		{
			sx = i;
			sy = j;
		}
	bfs(ex,ey,n,m);
	int res = 0;
	rep(i,0,n)
		rep(j,0,m)
			if (isdigit(A[i][j]) && D[i][j]<=D[sx][sy] && D[i][j]!=-1)
				res+=A[i][j]-'0';
	cout<<res<<endl;
}

//#define problem "party"


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(problem".in","r",stdin);
	//freopen(problem".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}