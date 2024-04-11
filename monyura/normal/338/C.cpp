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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;


ll A[10];
int Cnt[10]={0};
int D[1<<8][1<<8];
int n;
const int INF=1e9;

int rec(int rootMask, int usedMask)
{
	int &val = D[rootMask][usedMask];
	if (val!=-1)
		return val;
	val = INF;
	if (usedMask == (1<<n)-1)
	{
		val = 0;
		rep(j,0,n)
			if (((rootMask)>>j)&1)
				val += Cnt[j]>1 ? Cnt[j] : 0;
		return val;
	}
	int Dels[8];
	int dcnt = 0;
	rep(i,0,n)
		if ((rootMask>>i)&1)
		{
			ll rt = A[i];
			dcnt=0;
			rep(j,0,n)
				if (!((usedMask>>j)&1) && rt % A[j]==0)
				{
					Dels[dcnt++] = j;
				}
			rep(j,1,1<<dcnt)
			{
				ll curr = Cnt[i];
				int nextMask = 0;
				bool ok = true;
				ll was = rt;
				rep(k,0,dcnt)
					if ((j>>k)&1)
					{
						if (was % A[Dels[k]] !=0)
						{
							ok = false;
							break;
						}
						was /= A[Dels[k]];
						curr -= Cnt[Dels[k]];
						++curr;
						nextMask |= 1<<Dels[k];
					}
				if (!ok) 
					continue;
				int nextRoot = (rootMask ^ (1<<i)) | nextMask;
				int nextUsed = usedMask | nextMask;
				curr += rec(nextRoot, nextUsed);
				if (curr<val)
					val = curr;
			}
		}
	return val;
}

void run()
{
	memset(D,-1,sizeof(D));
	cin>>n;	
	rep(i,0,n)
		cin>>A[i];
	rep(t,0,n)
	{
		ll a = A[t];
		for (int i = 2; i*ll(i)<=a;i++)
			while (a%i==0)
			{
				Cnt[t]++;
				a/=i;
			}
		if (a!=1)
			Cnt[t]++;
	}
	ll res = INF;
	rep(i,1,1<<n)
	{
		int rootMask = i;
		int usedMask = i;
		ll val = rec(rootMask, usedMask);
		int cnt = 0;
		rep(j,0,n)
			if ((i>>j)&1)
				++cnt;
		val += cnt;
		if (cnt>1)
			++val;
		res = min(res,val);
	}
	cout<<res<<endl;
}

//#define prob "fibsubseq"

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(prob".in","r",stdin);
	//freopen(prob".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf( "\n=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}