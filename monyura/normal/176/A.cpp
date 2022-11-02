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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


void run()
{
	int n,m,k;
	cin>>n>>m>>k;
	int res=0;
	int A[10][101],B[10][101],C[10][101];
	char tmp[100];
	rep(i,0,n)
	{
		scanf(" %s",tmp);
		rep(j,0,m)
			scanf("%d%d%d",&A[i][j],&B[i][j],&C[i][j]);
	}
	rep(i,0,n)
		rep(j,0,n)
		if (i!=j)
		{
			vector<pii> vec;
			rep(t,0,m)
				if (A[i][t]<B[j][t]) vec.push_back(pii(B[j][t]-A[i][t],t));
			sort(all(vec),greater<pii>());
			int left=k;
			int curr=0;
			rep(t,0,vec.size())
				if (left>0)
				{
					int can=min(left,C[i][vec[t].second]);
					left-=can;
					curr+=can*vec[t].first;
				}
				else
					break;
			movmax(res,curr);
		}
	cout<<res<<endl;

}

int main()
{

#ifdef _MON_JUDGE_
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MON_JUDGE_
	puts("=================");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/