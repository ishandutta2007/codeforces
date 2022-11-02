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
#include <complex>
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
const int Lower[4]={1e9,0,10,100};

vector<string> res;

char str[100];
char A[10];
int cnt;

int len;

int Pos[5];
char buff[100];
void points(int pos,int cnt,int last)
{
	if (cnt==3)
	{
		if (0<len-1-last && len-1-last<=3)
		{
			int curr = len-1-last;
			int val = 0;
			rep(j,0,curr)
				val=val*10+str[last+1+j]-'0';
			if (Lower[curr]<=val && val<=255)
			{
				int pntr = 0;
				int putPoints = 0;
				rep(i,0,len)
				{
					buff[pntr++]=str[i];
					if (Pos[putPoints]==i)
					{
						buff[pntr++]='.';
						putPoints++;
					}
				}
				buff[pntr]=0;
				res.push_back(buff);
			}
				
		}
		return;
	}
	int val = 0;
	rep(t,0,3)
		if (pos+t<len)
		{
			val=val*10+str[pos+t]-'0';
			if (Lower[t+1]<=val && val<=255)
			{
				Pos[cnt] = pos+t;
				points(pos+t+1,cnt+1,pos+t);
			}
		}
}

bool used[10]={0};
int usedCnt = 0;
void rec(int pos)
{
	if (2<=pos && pos<=6 && usedCnt==cnt)
	{
		len = 2*pos;
		rep(i,0,pos)
			str[pos+i]=str[pos-1-i];
		points(0,0,0);
		if (pos==6 && strncmp(str,"781902",6)==0)
			int as=2;
		len = 2*pos - 1;
		rep(i,0,pos-1)
			str[pos+i]=str[pos-2-i];
		points(0,0,0);
	}
	if (pos==6) return;
	rep(i,0,cnt)
	{
		int was = used[i];
		if (!used[i]) ++usedCnt;
		used[i]=1;
		str[pos]=A[i];
		rec(pos+1);
		used[i]=was;
		if (was==0) --usedCnt;
	}
}

void run()
{
	scanf("%d",&cnt);
	rep(i,0,cnt)
	{
		int a;
		scanf("%d",&a);
		A[i]=a+'0';
	}
	if (cnt>6)
	{
		puts("0");
		return;
	}
	sort(A,A+cnt);
	rec(0);
	printf("%d\n",res.size());
	rep(i,0,res.size())
		printf("%s\n",res[i].c_str());
}

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("path.in","r",stdin);
	//freopen("path.out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*

*/