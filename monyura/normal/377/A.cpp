#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <iomanip>
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
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

const double PI = acos(-1.0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;



void run()
{
	int n,m,k;
	cin>>n>>m>>k;
	char A[501][501];
	rep(i,0,n)
		scanf("%s",A+i);
	int D[501][501];
	memset(D,-1,sizeof(D));
	queue<pii> q;
	int dx[]={-1,0,1,0};
	int dy[]={0,-1,0,1};
	pii st(-1,-1);
	rep(i,0,n)
		rep(j,0,m)
			if (A[i][j] == '.')
				st = pii(i,j);
	vector<pair<int,pii> > vec;
	if (st.first != -1)
	{
		q.push(st);
		D[st.first][st.second] = 0;
		while (!q.empty())
		{
			pii p = q.front();
			vec.push_back(pair<int, pii>(D[p.first][p.second], p));
			q.pop();
			rep(k,0,4)
			{
				pii nxt(p.first + dx[k], p.second + dy[k]);
				if (nxt.first>=0 && nxt.first < n && nxt.second>=0 && nxt.second<m 
					&& A[nxt.first][nxt.second] == '.' && D[nxt.first][nxt.second] == -1)
				{
					q.push(nxt);
					D[nxt.first][nxt.second] = D[p.first][p.second] + 1;
				}
			}
		}
	}
	sort(all(vec));
	reverse(all(vec));
	rep(i,0,k)
		A[vec[i].second.first][vec[i].second.second] = 'X';
	rep(i,0,n)
		puts(A[i]);
}	


//#define prob "xoring"


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	#ifdef prob
		freopen(prob".in","r",stdin);
		freopen(prob".out","w",stdout);
	#endif
#endif
	run();
		//testFft();
#ifdef _MONYURA_
	printf( "\n=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}