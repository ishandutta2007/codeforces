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

const int SZ=1000002;
ll IncA[SZ]={0};
ll IncDA[SZ]={0};
ll Add[SZ]={0};
ll DecA[SZ]={0};
ll DecDA[SZ]={0};

void update(ll val,int cntl,int cntr)
{
	if (cntl>cntr) 
		swap(cntl,cntr);
	IncA[1]+=val;
	IncA[cntl+1]-=val;
	IncDA[cntl+1]-=cntl*val;

	Add[cntl+1]+=(cntl+1)*val;
	Add[cntr+1+1]-=(cntl+1)*val;
	
	int n=cntl+cntr+1;
	DecA[n]+=val;
	DecA[cntr+1]-=val;
	DecDA[cntr+1]-=cntl*val;
}

void summAll(int n)
{
	ll curr=0;
	rep(i,1,n+1)
	{
		curr+=Add[i];
		Add[i]=curr;
	}
	ll sumA=0,sumDA=0;
	rep(i,1,n+1)
	{
		sumA+=IncA[i];
		sumDA+=IncDA[i]+sumA;
		Add[i]+=sumDA;
	}
	sumA=sumDA=0;
	for (int i=n;i>=1;i--)
	{
		sumA+=DecA[i];
		sumDA+=DecDA[i]+sumA;
		Add[i]+=sumDA;
	}
}

void run()
{
	int n;
	cin>>n;
	pii P[SZ];
	rep(i,0,n)
	{
		scanf("%d",&P[i].first);
		P[i].second=i;
	}
	sort(P,P+n);
	set<pii> st;
	st.insert(pii(n-1,0));
	set<pii>::iterator iter;
	pii pr;
	rep(i,0,n)
	{
		iter=st.lower_bound(pii(P[i].second,0));
		if (iter==st.end())
		{
			fprintf(stderr,"Holly shit");
			return;
		}
		pr=*iter;
		st.erase(iter);
		if (pr.first>=P[i].second+1)
			st.insert(pii(pr.first,P[i].second+1));
		if (P[i].second-1>=pr.second)
			st.insert(pii(P[i].second-1,pr.second));
		update(P[i].first,P[i].second-pr.second,pr.first-P[i].second);
	}
	summAll(n);
	int m;
	cin>>m;
	rep(i,0,m)
	{
		int k;
		scanf("%d",&k);
		printf("%.10lf\n",Add[k]/double(n-k+1));
	}

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