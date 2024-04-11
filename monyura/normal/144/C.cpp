//#pragma comment(linker,"/STACK:62000000")
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
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int main()
{
	char s[100001];
	char p[100001];
	scanf("%s %s",s,p);
	int cnt[300]={0};
	int A[300]={0};
	int n=strlen(s);
	int m=strlen(p);
	if (n<m)
	{
		printf("0\n");
		return 0;
	}
	rep(i,0,m)
	{
		cnt[s[i]]++;
		A[p[i]]++;
	}
	int res=0;
	bool ok=1;
	int left=0;
	rep(c,'a','z'+1)
		if (cnt[c]<=A[c])
			left+=A[c]-cnt[c];
		else
			ok=0;
	if (ok && left==cnt['?'])
		res++;
	rep(i,1,n-m+1)
	{
		cnt[s[i-1]]--;
		cnt[s[i+m-1]]++;
		bool ok=1;
		int left=0;
		rep(c,'a','z'+1)
			if (cnt[c]<=A[c])
				left+=A[c]-cnt[c];
			else
				ok=0;
		if (ok && left==cnt['?'])
			res++;
	}
	printf("%d\n",res);	
	return 0;
} 

/*

*/