#pragma comment(linker,"/STACK:128000000")
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


void run()
{
	int n;
	cin>>n;
	int A[2002][2002]={0};
	rep(i,0,n)
		rep(j,0,n)
			scanf("%d",&A[i+1][j+1]);
	int dx[4]={-1,0,1,0};
	int dy[4]={0,-1,0,1};
	int Cir=0,Sq=0;
	rep(i,1,n)
		rep(j,1,n)
			if (A[i][j])
			{
				queue<pii> q;
				A[i][j]=0;
				q.push(pii(i,j));
				int cnt=1;
				int mxx=i;
				while (!q.empty())
				{
					int xi=q.front().x;
					int xj=q.front().y;
					q.pop();
					rep(k,0,4)
						if (A[xi+dx[k]][xj+dy[k]])
						{
							cnt++;
							A[xi+dx[k]][xj+dy[k]]=0;
							movmax(mxx,xi+dx[k]);
							q.push(pii(xi+dx[k],xj+dy[k]));
						}
				}
				double sq=PI*SQR(i-mxx)/4.0;
				if (fabs(sq-cnt)<50)
					Cir++;
				else
					Sq++;
			}
		cout<<Cir<<' '<<Sq<<endl;
}

int main()
{

#ifdef _MON_JUDGE_
	freopen("e-samples\\medium_2.in","r",stdin);
	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	/*freopen("out.txt","w",stdout);*/
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