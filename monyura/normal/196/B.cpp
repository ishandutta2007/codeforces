//#pragma comment(linker,"/STACK:128000000")
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

typedef unsigned long long ll;
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


struct elem
{
	short x,y;
	int val;
	elem(){}
	elem(short x0,short y0,int v)
	{
		x=x0;
		y=y0;
		val=v;
	}
};

char A[1505][1505];
int Was[1505][1505];
elem Q[3000000];

void gen()
{
	printf("1500 1500\n");
	rep(i,0,1500)
	{
		rep(j,0,1500)
			if (i!=750 || j!=750)
				putchar('.');
			else putchar('S');
		printf("\n");
	}

}

void run()
{
	int n,m;
	cin>>n>>m;
	pii st;
	rep(i,0,n)
	{
		scanf(" %s",A[i]);
		rep(j,0,m)
			if (A[i][j]=='S') st=pii(i,j);
	}
	rep(i,0,n)
		rep(j,0,m)
			Was[i][j]=1e9;
	int dx[4]={-1,0,1,0};
	int dy[4]={0,-1,0,1};
	int H=0,T=0;
	Q[T++]=elem(st.first,st.second,0);
	Was[st.first][st.second]=0;
	A[st.first][st.second]='.';
	elem c;
	short x,y;
	int val;
	bool res=false;
	while (T!=H && !res)
	{
		c=Q[H++];
		rep(k,0,4)
		{
			x=c.x+dx[k];
			y=c.y+dy[k];
			val=c.val;
			if (x<0) {x=n-1;val-=2000;}
			if (x==n){x=0;val+=2000;}
			if (y<0) {y=m-1;val--;}
			if (y==m) {y=0;val++;}
			if (A[x][y]=='.')
			{
				if (Was[x][y]==1e9)
				{
					Was[x][y]=val;
					Q[T++]=elem(x,y,val);
				}
				else if (Was[x][y]!=val)
				{
					res=true;
					break;
				}
			}
		}
	}
	puts(res?"Yes":"No");
}

int main()
{
#ifdef _MONYURA_
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
#endif
	time_t beg=clock();
	//gen();
	run();
#ifdef _MONYURA_
	printf("================\n");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/