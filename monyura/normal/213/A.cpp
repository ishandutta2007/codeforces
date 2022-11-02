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

int Cnt[201]={0};
bool was[201];
int A[201];
int C[201];
vector<int> inc[201];
int model_it(int c,int n)
{
	int res=n;
	int left=n;
	rep(i,0,n)
	{
		rep(t,0,3)
		{
			bool ok=1;
			while (ok)
			{
				ok=0;
				rep(j,0,n)
					if (!was[j] && A[j]==0 && C[j]==c)
					{
						ok=1;
						was[j]=1;
						--left;
						rep(k,0,inc[j].size())
							--A[inc[j][k]];
					}
			}
			if (left==0) return res;
			c=c%3+1;
			++res;
		}
	}
	return res;
}

void run()
{
	int n;
	cin>>n;
	rep(i,0,n)
		scanf("%d",C+i);
	rep(i,0,n)
	{
		int k;
		scanf("%d",&k);
		Cnt[i]=k;
		rep(j,0,k)
		{
			int fr;
			scanf("%d",&fr);
			--fr;
			inc[fr].push_back(i);
		}
	}
	int res=1e9;
	rep(i,1,4)
	{
		memset(was,0,sizeof(was));
		memcpy(A,Cnt,sizeof(A));
		int curr=model_it(i,n);
		if (curr<res)
			res=curr;
	}
	cout<<res<<endl;
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