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


void run()
{
	int n,k;
	cin>>n>>k;
	char Str[2][100100];
	scanf("%s %s",Str[0],Str[1]);
	int dist[2][100100];
	int INF=1e9;
	rep(i,0,2)
		rep(j,0,n)
			if (Str[i][j]=='-')
				dist[i][j]=INF;
			else
				dist[i][j]=-1;
	dist[0][0]=0;
	queue<pii> q;
	q.push(pii(0,0));
	bool win=false;
	while (!q.empty())
	{
		int curr=q.front().first;
		int st=q.front().second;
		q.pop();
		if (curr>=0 && dist[st][curr]<curr-1 && dist[st][curr-1]==INF)
		{
			dist[st][curr-1]=dist[st][curr]+1;
			q.push(pii(curr-1,st));
		}
		if (curr+1>=n) win=true;
		if (curr+1<n && dist[st][curr]<curr+1 && dist[st][curr+1]==INF)
		{
			dist[st][curr+1]=dist[st][curr]+1;
			q.push(pii(curr+1,st));
		}
		if (curr+k>=n) win=true;
		if (curr+k<n && dist[st][curr]<curr+k && dist[st^1][curr+k]==INF)
		{
			dist[st^1][curr+k]=dist[st][curr]+1;
			q.push(pii(curr+k,st^1));
		}
	}
	puts(win?"YES":"NO");
	
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