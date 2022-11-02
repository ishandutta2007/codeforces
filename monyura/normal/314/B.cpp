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

int getCnt(char *A,char *C,int posa,int b)
{
	int cntc = 0;
	int cnta = 0;
	int lenc = strlen(C), lena = strlen(A);
	while (cnta<b)
	{
		int posc = 0;
		while (cnta<b && posc<lenc)
		{
			for (;posa<lena && posc<lenc;posa++)
				if (A[posa]==C[posc])
					++posc;
			if (posc==lenc)
			{
				++cntc;
				if (posa==lena)
				{
					posa=0;
					++cnta;
				}
			}
			else
			{
				posa = 0;
				++cnta;
			}
		}
	}
	return cntc;
}

ll getRes(char *A,char *C,int b,int d)
{
	int lenc = strlen(C);
	int lena = strlen(A);
	int D[200];
	int Cwas[200];
	memset(D,-1,sizeof(D));
	int cnta=0,cntc=0;
	int posa = 0;
	int found = -1;
	while (cnta<b && found==-1 && cnta<10100)
	{
		int posc = 0;
		while (cnta<b && cnta<10100 && posc<lenc)
		{
			for (;posa<lena && posc<lenc;posa++)
				if (A[posa]==C[posc])
					++posc;
			if (posc==lenc)
			{
				++cntc;
				if (posa==lena)
				{
					posa=0;
					++cnta;
				}
				if (D[posa]==-1)
				{
					D[posa]=cnta;
					Cwas[posa]=cntc;
				}
				else
					found = posa;
			}
			else
			{
				posa = 0;
				++cnta;
			}
		}
	}
	if (cnta==10100)
	{
		return 0;
	}
	ll realCnt = cntc;
	if (found!=-1)
	{
		ll inPer = cntc-Cwas[posa];
		b-=D[posa];
		int perLen = cnta-D[posa];
		int cnt = (b-1) / perLen;
		realCnt = Cwas[posa];
		if (cnt>0)
		{
			realCnt += inPer * cnt;
			int rem = (b-1) % perLen + 1;
			realCnt += getCnt(A,C,posa,rem);
		}
	}
	ll p = realCnt/d;
	return p;
}

ll BF(char *A,char *C,int b,int d)
{
	static char buff[10000000];
	buff[0]=0;
	rep(i,0,b)
		strcat(buff,A);
	int res = 0;
	int posc = 0;
	int lenc = strlen(C);
	rep(i,0,strlen(buff))
		if (buff[i]==C[posc])
		{
			++posc;
			if (posc==lenc)
			{
				++res;
				posc=0;
			}

		}
	return res/d;
}

void run()
{
	int b,d;
	char A[200],C[200];
	cin>>b>>d;
	scanf("%s %s",A,C);
	ll res = getRes(A,C,b,d);
	cout<<res<<endl;
	/*int done = 0;
	rep(i,0,10000)
	{
		int lenc = rand()%3 +1;
		int lena = rand()%3 +1;
		int b = rand()%1000+1;
		int c = rand()%1000+1;
		if (lena*b>=10000000)
			continue;
		++done;
		cerr<<done<<' ';
		rep(i,0,lenc)
			C[i] = rand()%3+'a';
		rep(i,0,lena)
			A[i] = rand()%3+'a';
		ll res1 = getRes(A,C,b,d);
		ll res2 = BF(A,C,b,d);
		if (res1!=res2)
		{
			cerr<<"fail at "<<done<<endl;
			return;
		}
	}
	cerr<<"Ok: "<<done<<endl;*/
	
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