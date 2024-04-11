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

   
void run()
{
	char str[1001];
	scanf("%s",str);
	int n;
	cin>>n;
	int Cnt[26]={0};
	rep(i,0,strlen(str))
		Cnt[str[i]-'a']++;
	rep(i,1,1001)
	{
		int curr = 0;
		rep(j,0,26)
			curr += (Cnt[j]+i-1)/i;
		if (curr<=n)
		{
			vector<char> vec;
			rep(j,0,26)
			{
				int val = Cnt[j];
				while (val>0)
				{
					int curr = min(val,i);
					vec.push_back(j+'a');
					val-=curr;
				}
			}
			rep(j,0,n-curr)
				vec.push_back('z');
			printf("%d\n",i);
			rep(j,0,vec.size())
				printf("%c",(char)vec[j]);
			puts("");
			return;
		}

	}
	cout<<-1<<endl;
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