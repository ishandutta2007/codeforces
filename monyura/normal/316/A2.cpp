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


void run()
{
	char str[100100];
	scanf("%s",str);
	set<char> st;
	int q = 0;
	rep(i,0,strlen(str))
		if (str[i]>='A' && str[i]<='Z')
			st.insert(str[i]);
		else if (str[i]=='?')
			++q;
	int cnt = st.size();
	if (cnt>10)
	{
		puts("0");
		return;
	}
	ll has = 1;
	if (str[0]>='A' && str[0]<='Z')
	{
		has*=9;
		rep(i,0,cnt-1)
			has*=9-i;
	}
	else
	{
		rep(i,0,cnt)
			has*=10-i;
	}
	if (str[0]=='?')
	{
		has*=9;
		--q;
	}
	cout<<has;
	char res[100100]={0};
	rep(i,0,q)
		res[i]='0';
	puts(res);
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