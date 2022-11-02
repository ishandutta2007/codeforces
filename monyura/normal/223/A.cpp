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


void run()
{
	char str[100100]={0};
	scanf("%s",str);
	vector<int> vec;
	int best=-1,bestA=-1,bestB=-1;
	int curr=0,A=1e9,B=1e9;
	int n=strlen(str);
	int Cnt[100100]={0};
	int Best[100100];
	int Start[100100];
	memset(Best,-1,sizeof(Best));
	rep(i,0,n)
	{
		if (str[i]=='(' || str[i]=='[')
		{
			Cnt[i]=curr;
			vec.push_back(i);
		}
		else
		{
			if (!vec.empty() && (str[vec.back()]=='(' && str[i]==')' || str[vec.back()]=='[' && str[i]==']'))
			{
				if (str[i]==']')
					curr++;
				Best[i]=curr - Cnt[vec.back()];
				Start[i]=vec.back();
				if (vec.back()!=0 && Best[vec.back()-1]!=-1)
				{
					Best[i]+=Best[vec.back()-1];
					Start[i]=Start[vec.back()-1];
				}
				vec.pop_back();
			}
			else
				vec.clear();
		}
	}
	rep(i,0,n)
		if (Best[i]>best)
		{
			best=Best[i];
			bestA=Start[i];
			bestB=i;
		}
	if (best==-1)
	{
		rep(i,0,n-1)
			if (str[i]=='(' && str[i+1]==')')
			{
				best=0;
				bestA=i;
				bestB=i+1;
				break;
			}
	}
	if (best==-1)
		printf("0\n");
	else
	{
		printf("%d\n",best);
		str[bestB+1]=0;
		printf("%s\n",str+bestA);
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