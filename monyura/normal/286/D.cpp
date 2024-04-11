//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI = acos(-1.0);

const int SZ = 100100;


struct line
{
	int l,r,t;
	bool operator<(const line &a)
	{
		return t<a.t;
	}
};


int Added[SZ]= {0};
int Plus[SZ] = {0};
int Minus[SZ] = {0};
int Cnt[SZ] = {0};
int q[SZ];
int n;
set<pii> st;
typedef set<pii>::iterator iter;

void printSt()
{
	for (iter i = st.begin();i!=st.end();i++)
		printf("(%d, %d) ",i->first,i->second);
	puts("");
}


void procOtr(int l,int r,int t)
{
	if (l==r) return;
	int a = lower_bound(q,q+n,t-r)-q;
	int b = upper_bound(q,q+n,t-l)-q-1;
	if (a<=b)
	{
		Plus[b] += r - (t-q[b]);
		Minus[a]+= r - (t-q[a]);
		Cnt[b]++;
		Cnt[a]--;
	}
	Added[n-1]+= r-l;
	if (b>=0 && b<n)
		Added[b]-=r-l;
}


const int INF = 1e9+10;
void addLine(const line &seg)
{
	iter curr;
	curr  = st.lower_bound(pii(seg.l,-1));
	if (curr!=st.begin())
		--curr;
	if (curr!=st.end() && curr->first<=seg.l && curr->second>=seg.r)
		return;
	if (curr!=st.end() && curr->first<seg.l && curr->second>seg.l)
	{
		pii A(curr->first,seg.l);
		pii B(seg.l,curr->second);
		st.erase(curr);
		st.insert(A);
		st.insert(B);
	}
	curr = st.lower_bound(pii(seg.r,-1));
	if (curr!=st.begin())
		--curr;
	if (curr!=st.end() && curr->first<seg.r && curr->second>seg.r)
	{
		pii A(curr->first,seg.r);
		pii B(seg.r,curr->second);
		st.erase(curr);
		st.insert(A);
		st.insert(B);
	}
	vector<iter> toDel;
	int prev = seg.l;
	for (iter it = st.lower_bound(pii(seg.l,-1));it!=st.upper_bound(pii(seg.r,-1));++it)
	{
		procOtr(prev,it->first,seg.t);
		prev = it->second;
		toDel.push_back(it);
	}
	procOtr(prev,seg.r,seg.t);
	rep(i,0,toDel.size())
		st.erase(toDel[i]);
	st.insert(pii(seg.l,seg.r));
	//printSt();
}


void run()
{
	int m;
	cin>>n>>m;
	line L[SZ];
	rep(i,0,m)
		scanf("%d%d%d",&L[i].l,&L[i].r,&L[i].t);
	sort(L,L+m);
	rep(i,0,n)
		scanf("%d",q+i);
	rep(i,0,m)
		addLine(L[i]);
	ll sum = 0;
	int Ans[SZ]={0};
	int cnt=0;
	for (int i=n-1;i>=0;i--)
	{
		cnt+=Cnt[i];
		sum+=Added[i];
		sum+=Plus[i];
		Ans[i]+=sum;
		sum-=Minus[i];
		if (i>0)
			sum-=ll(cnt)*(q[i]-q[i-1]);
	}
	rep(i,0,n)
		printf("%d\n",Ans[i]);
}





int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);	
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
3
abcdefghABCDEFGH
3
abc
a
abAB
xyz
1
xyz
abacaba
6
a
aba
caba 
acaba
ba
bacb
*/