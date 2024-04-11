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

//vector<int> par[7001];
//
//int cnt = 0;
//void build(int n)
//{
//	cnt = 1;
//	par[1].push_back(-1);
//	for (int lvl = 1; lvl < n; lvl++)
//	{
//		for (int pos = 0; pos < par[lvl].size(); pos++)
//		{
//			int c = pos+1;
//			if ((c&-c)==c)
//			{
//				par[lvl+1].push_back(pos);
//				par[lvl+1].push_back(pos);
//				cnt+=2;
//			}
//			else
//			{
//				par[lvl+1].push_back(pos);
//				cnt++;
//			}
//		}
//		cout<<cnt<<endl;
//	}
//}

const int mod = 1e9+7;

ll toPow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return res;
}

ll fact[100100];
ll revFact[100100];

void init()
{
	fact[0] = 1;
	rep(i,1,100100)
		fact[i] = (fact[i-1] * i) % mod;
	rep(i,0,100100)
		revFact[i] = toPow(fact[i], mod-2);
}

ll Cnk(int n, int k)
{
	if (n < k) return 0;
	return fact[n] * revFact[k] % mod * revFact[n-k] % mod;
}


ll run(int *A, int n, vector<pii> &P,int l, int r)
{
	rep(i,l,r+1)
		if (A[i] != 0 && A[i] != P[0].first)
			return 0;
	ll res = 1;
	rep(i,0, P.size()-1)
	{
		int curr = P[i].second;
		int nxt = P[i+1].second;
		int diff = P[i+1].first - P[i].first -1;
		int diffInPos = nxt > curr ? nxt - r - 1 : l - nxt - 1;
		if (diffInPos > diff)
			return 0;
		if (nxt > curr)
		{
			rep(j,r+1,nxt)
				if (A[j] != 0)
					return 0;
			int total = l + diffInPos;
			if (total < diff)
				return 0;
			res = (res * Cnk(diff,diffInPos)) % mod;
			r = nxt;
			rep(j,0, diff - diffInPos)
			{
				l--;
				if (A[l] != 0)
					return 0;
			}
		}
		else
		{
			rep(j,nxt+1,l)
				if (A[j] != 0)
					return 0;
			int total = diffInPos + (n - 1 - r);
			if (total < diff)
				return 0;
			res = (res * Cnk(diff, diffInPos)) % mod;
			l = nxt;
			rep(j,0, diff - diffInPos)
			{
				r++;
				if (A[r] != 0)
					return 0;
			}
		}
	}
	int left = l;
	int right = n - 1 -r;
	res = (res * Cnk(left + right, left));
	return res;
}


ll model(int *A, int n)
{
	vector<pii> P;
	rep(i,0,n)
		if (A[i] != 0)
			P.push_back(pii(A[i],i));
	sort(all(P));
	if (P.size() == 0)
		return toPow(2,n-1);
	int leftOne = P[0].second;
	int rightOne = n - 1 - P[0].second;
	int need = P[0].first-1;
	ll res = 0;
	if (leftOne >= need)
		res = (res + toPow(2,max(need-1,0)) * run(A,n,P,P[0].second-need,P[0].second)) % mod;
	if (need != 0)
	{
		if (rightOne >= need)
			res = (res + toPow(2,max(need-1,0)) * run(A,n,P,P[0].second, P[0].second+need)) % mod;
	}
	return res;
}

bool isOk(int *A, int n, int *P)
{
	rep(i,0,n)
		if (A[i] != 0 && A[i] != P[i])
			return false;
	int B[20]={0};
	rep(i,0,n)
	{
		int pos = -1;
		rep(j,0,n)
			if (P[j] == i+1)
			{
				pos = j;
				break;
			}
		if (pos-1>=0 && B[pos-1]!=0 && pos+1 <n && B[pos+1] != 0)
			return false;
		B[pos] = 1;
	}
	return true;
}

ll bf(int *A, int n)
{
	int P[100];
	rep(i,0,n)
		P[i] = i+1;
	int res = 0;
	do
	{
		res += isOk(A,n,P);
	}
	while (next_permutation(P,P+n));
	return res;
}

void check()
{
	rep(iter,0,200)
	{
		int n = rand()%9 + 1;
		int P[10];
		rep(j,0,n)
			P[j] = j+1;
		random_shuffle(P,P+n);
		rep(j,0,n)
			if (rand()%2 == 0)
				P[j] = 0;
		ll r1 = model(P,n);
		ll r2 = bf(P,n);
		if (r1 != r2)
		{
			cerr<<"fail"<<endl;
			printf("%d\n",n);
			rep(j,0,n)
				printf("%d ",P[j]);
			puts("");
			return;
		}
	}
}

void run()
{
	init();
	/*check();
	return;
	*/
	int n;
	cin>>n;
	int A[100100];
	rep(i,0,n)
		scanf("%d",A+i);
	if (*max_element(A,A+n) == 0)
	{
		ll res = toPow(2,n-1);
		cout<<res<<endl;
		return;
	}
	ll res = model(A,n);
	cout<<res<<endl;	
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
#ifdef _MONYURA_
	printf( "\n=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}