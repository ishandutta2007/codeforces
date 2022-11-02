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
	char str[1000100];
	scanf("%s",str);
	int n=strlen(str);
	int m;
	cin>>m;
	int A[10001];
	int B[10001];
	map<int,int> res;
	char pat[100];
	rep(i,0,m)
	{
		scanf(" %s",pat);
		int mask=0;
		rep(j,0,strlen(pat))
			mask|=1<<(pat[j]-'a');
		B[i]=A[i]=mask;
	}
	sort(B,B+m);
	int Pos[26]={0};
	rep(i,0,26)
		Pos[i]=-1;
	int mask=0,curr;
	pii P[26];
	str[n]='z'+1;
	rep(i,0,n)
	{
		mask|=1<<(str[i]-'a');
		Pos[str[i]-'a']=i;
		rep(j,0,26)
		{
			P[j].first=Pos[j];
			P[j].second=j;
		}
		sort(P,P+26);
		curr=mask;
		int next=1<<(str[i+1]-'a');
		if (binary_search(B,B+m,mask) && (mask&next)==0)
			res[mask]++;
		rep(j,0,25)
			if (P[j].first!=-1)
			{
				curr&=~(1<<P[j].second);
				if (binary_search(B,B+m,curr) && (curr&next)==0)
					res[curr]++;
			}
	}
	rep(i,0,m)
		printf("%d\n",res[A[i]]);
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