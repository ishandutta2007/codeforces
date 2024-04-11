#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

char B[52][52];
int dx[4]={-1,0,1,0};
	int dy[4]={0,-1,0,1};
bool check(char A[52][52],int n,int m,int x,int y)
{
	memcpy(B,A,sizeof(char)*52*52);
	B[x][y]='.';
	int sti,stj=-1;
	rep(i,1,n+1)
		rep(j,1,m+1)
		if (B[i][j]=='#')
		{
			sti=i;
			stj=j;
		}
	if (stj==-1) return false;
	queue<pii> q;
	q.push(pii(sti,stj));
	while (!q.empty())
	{
		int i=q.front().first;
		int j=q.front().second;
		q.pop();
		rep(k,0,4)
			if (B[i+dx[k]][j+dy[k]]=='#')
			{
				q.push(pii(i+dx[k],j+dy[k]));
				B[i+dx[k]][j+dy[k]]='.';
			}
	}
	rep(i,1,n+1)
		rep(j,1,m+1)
			if (B[i][j]=='#')
				return true;
	return false;
}

void run()
{
	int n,m;
	cin>>n>>m;
	char A[52][52];
	memset(A,'.',sizeof(A));
	rep(i,1,n+1)
		scanf(" %s",A[i]+1);
	int res=2;
	int cnt=0;
	rep(i,1,n+1)
		rep(j,1,m+1)
			if (A[i][j]=='#')
				++cnt;
	if (cnt<=2)
	{
		printf("-1\n");
		return;
	}
	rep(i,1,n+1)
		rep(j,1,m+1)
			if (A[i][j]=='#')
			{
				if (check(A,n,m,i,j))
				{
					res=1;
					break;
				}
			}
	printf("%d\n",res);
}


int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/