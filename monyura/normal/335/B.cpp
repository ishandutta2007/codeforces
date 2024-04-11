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

const int TO = 2605;
int D[TO][TO]={0};
pii From[TO][TO];
char B[TO][TO];
   
void run()
{
	char str[50100];
	scanf("%s",str);
	int n = strlen(str);
	if (n>=2600)
	{
		int Cnt[26]={0};
		rep(j,0,n)
			Cnt[str[j]-'a']++;
		rep(j,0,26)
			if (Cnt[j]>=100)
			{
				rep(k,0,100)
					printf("%c",(char)(j+'a'));
				puts("");
				return;
			}
	}
	rep(i,0,n+1)
		rep(j,0,n)
			From[i][j]=pii(-1,-1);
	rep(i,0,n)
		D[1][i] = 1;
	rep(len,2,n+1)
		rep(i,0,n)
			if (i+len-1<n)
			{
				D[len][i] = D[len-1][i];
				From[len][i] = pii(len-1,i);
				B[len][i] = 0;
				if (D[len][i] < D[len-2][i+1] + 2*(str[i]==str[i+len-1]))
				{
					D[len][i] = D[len-2][i+1] + 2*(str[i]==str[i+len-1]);
					From[len][i] = pii(len-2,i+1);
					B[len][i] = str[i];
				}
				if (D[len-1][i+1] > D[len][i])
				{
					D[len][i] = D[len-1][i+1];
					From[len][i] =pii(len-1,i+1);
					B[len][i] = 0;
				}
			}
	int mx = -1;
	int mlen = 1,mi = 0;
	bool deleteOdd = false;
	rep(len,1,n+1)
		rep(i,0,n)
		{
			if (D[len][i]>mx)
			{
				mx = D[len][i];
				mlen  = len;
				mi = i;
			}
			if (D[len][i]==101)
			{
				mx = 101;
				mlen = len;
				mi = i;
				deleteOdd = true;
				goto stop; //sorry Dijsktra
			}
		}
stop:
	vector<char> vec;
	//cerr<<mx<<endl;
	char odd = str[0];
	while (mlen>1)
	{
		if (B[mlen][mi])
			vec.push_back(B[mlen][mi]);
		int nlen = From[mlen][mi].first;
		int ni = From[mlen][mi].second;
		mlen = nlen;
		mi = ni;
		if (mlen==1)
		{
			odd = str[mi];
		}
		else if (mlen==0)
		{
			odd = 0;
		}
	}
	if (mx!=101)
	{
		reverse(all(vec));
		while (vec.size()>50)
			vec.pop_back();
		reverse(all(vec));
	}
	rep(i,0,vec.size())
		printf("%c",vec[i]);
	if (odd && !deleteOdd)
		printf("%c",odd);
	rep(i,0,vec.size())
		printf("%c",vec[vec.size()-1-i]);
	puts("");
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