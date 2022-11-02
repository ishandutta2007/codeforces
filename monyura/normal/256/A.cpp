#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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

bool was[1000100]={0};
vector<int> pos[1000100];
void run()
{	
	int n;
	cin>>n;
	int A[5000];
	rep(i,0,n)
		scanf("%d",A+i);
	rep(i,0,n)
		pos[A[i]].push_back(i);
	int res=1;
	rep(i,0,n)
	{
		rep(j,i+1,n)
		{
			int q = A[j] - A[i];
			if (!was[A[j]])
			{
				int cnt=2;
				int curr=A[j];
				int ind=j+1;
				while (1)
				{
					q=-q;
					curr+=q;
					vector<int>::iterator iter = lower_bound(all(pos[curr]),ind);
					if (iter==pos[curr].end())
						break;
					++cnt;
					ind=*iter+1;
				}
				res=max(res,cnt);
			}
		}
		was[A[i]]=1;
	}
	cout<<res<<endl;
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("freecell.in","r",stdin);
	//freopen("freecell.out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
10 10 92
11 10 92
*/