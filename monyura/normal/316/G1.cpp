#pragma comment(linker,"/STACK:65000000")
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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <assert.h>


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
typedef vector<int> vi;

const double PI = acos(-1.0);

const int c1 = 17531;
const int c2 = 301;
const int mod2 = 1e9+7;

//void KMP(char *str,int *S,int need)
//{
//	static int pref[6001];
//	pref[0]=0;
//	rep(i,1,strlen(str))
//	{
//		int curr = pref[i-1];
//		while (curr>0 && str[i]!=str[curr])
//			curr=pref[curr-1];
//		if (str[i]==str[curr])
//			++curr;
//		pref[i]=curr;
//		if (pref[i]==need)
//			S[i-1-need]=1;
//		else
//			S[i-1-need]=0;
//	}
//}

const int hSize = 512;
const int hMod = hSize-1;
struct hashTable
{
	vector<pii> lst[hSize];
	void add(const pii &p)
	{
		int h = (p.first^p.second)&hMod;
		for (int i=0;i<lst[h].size();i++)
			if (lst[h][i].first==p.second)
			{
				lst[h][i].second++;
				return;
			}
		lst[h].push_back(pii(p.second,1));
	}
	int get(const pii &p)
	{
		int h = (p.first^p.second)&hMod;
		for (int i=0;i<lst[h].size();i++)
			if (lst[h][i].first==p.second)
				return lst[h][i].second;
		return 0;
	}
};

hashTable mp[11][2002];

void prepare(char *str,int ind)
{
	int len = strlen(str);
	rep(i,0,len)
	{
		int h1 = 0;
		ll h2 = 0;
		rep(j,i,len)
		{
			h1 = h1*c1 + str[j];
			h2 = (h2*c2 + str[j])%mod2;
			mp[ind][j-i+1].add(pii(h1,h2));
		}
	}
}

void run()
{
	char A[3000];
	int S[11][3001]={0};
	int L[11],R[11];
	scanf("%s",A);
	int len = strlen(A);
	int n;
	cin>>n;
	rep(i,0,n)
	{
		char curr[6001];
		scanf("%s%d%d",curr,L+i,R+i);
		prepare(curr,i);
		/*int clen = strlen(curr);
		L[i]=clen;
		strcat(curr,"#");
		strcat(curr,A);
		KMP(curr,S[i],clen);
		rep(j,1,len)
			S[i][j]+=S[i][j-1];*/
	}
	pii Res[3000002];
	int pos = 0;
	rep(a,0,len)
	{
		int h1 = 0;
		ll h2 = 0;
		rep(b,a,len)
		{
			h1 = h1*c1 + A[b];
			h2 = (h2*c2 + A[b])%mod2;
			pii p(h1,h2);
			bool ok = true;
			rep(i,0,n)
			{
				int cnt = mp[i][b-a+1].get(p);
				if (L[i]>cnt || cnt>R[i])
				{
					ok=false;
					break;
				}
			}
			if (ok)
				Res[pos++]=p;
		}
	}
	sort(Res,Res+pos);
	int ans = unique(Res,Res+pos)-Res;
	cout<<ans<<endl;
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
24 54 96 108
*/