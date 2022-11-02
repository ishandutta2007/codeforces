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

int D[101][101][101];
pii from[101][101][101];
void run()
{
	char A[200];
	char B[200];
	char virus[200];
	scanf("%s %s %s",A,B,virus);
	int alen = strlen(A);
	int blen = strlen(B);
	int vlen = strlen(virus);
	vector<int> trans[102][30];
	int pref[102]={0};
	rep(i,1,vlen)
	{
		int curr = pref[i-1];
		while (curr > 0 && virus[curr] != virus[i])
			curr = pref[curr-1];
		if (virus[curr] == virus[i])
			++curr;
		pref[i] = curr;
	}
	rep(i, 0, vlen)
		rep(c,'A','Z'+1)
		{
			int curr = i;
			while (curr>0 && virus[curr] != c)
				curr = pref[curr-1];
			if (virus[curr] == c)
				++curr;
			trans[curr][c-'A'].push_back(i);
		}
	
	//
	//rep(i,0,vlen)
	//	cout<<pref[i]<<' ';
	//cout<<endl;
	//
	rep(a,0,alen)
		rep(b,0,blen)
			rep(pref,0,vlen)
			{
				int &curr = D[a][b][pref];
				pii &fr = from[a][b][pref];
				fr.first = -1;
				fr.second = -1;
				if (A[a] == B[b])
				{
					vector<int> &vec = trans[pref][A[a]-'A'];
					rep(i,0,vec.size())
					{
						fr.first = 2;
						int prev = 0;
						if (a>0 && b>0)
							prev = D[a-1][b-1][vec[i]];
						if (curr < prev + 1)
						{
							curr = prev + 1;
							fr.second = vec[i];
						}
					}
				}
				if (a>0 && D[a-1][b][pref] > curr)
				{
					curr = D[a-1][b][pref];
					fr.first = 0;
					fr.second = pref;
				}
				if (b>0 && D[a][b-1][pref] > curr)
				{
					curr = D[a][b-1][pref];
					fr.first = 1;
					fr.second = pref;	 
				}
			}
	int maxInd = 0;
	rep(i,1,vlen)
		if (D[alen-1][blen-1][i] > D[alen-1][blen-1][maxInd])
			maxInd = i;
	int a = alen-1, b = blen-1, pr = maxInd;
	char str[102]={0};
	int pos = 0;
	while (a>=0 && b>=0)
	{
		int na = a,nb = b;
		if (from[a][b][pr].first == 2)
		{
			str[pos++] = A[a];
			--na;
			--nb;
		}
		else if (from[a][b][pr].first == 1)
			--nb;
		else if (from[a][b][pr].first == 0)
			--na;
		else
			break;
		pr = from[a][b][pr].second;
		a = na;
		b = nb;
	}
	reverse(str,str+pos);
	if (D[alen-1][blen-1][maxInd] == 0)
		puts("0");
	else
		puts(str);
}

//#define prob "tria"

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