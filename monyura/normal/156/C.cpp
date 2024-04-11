#pragma comment(linker,"/STACK:64000000")
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
#define x first
#define y second

const double PI=acos(-1.0);


int main()
{
	int t;
	cin>>t;
	char str[200];
	int M=1000000007;
	int D[101][2501]={0};
	rep(i,0,26)
		D[0][i]=1;
	rep(i,1,101)
		rep(s,0,2501)
			rep(j,0,26)
				if (s-j>=0)
					D[i][s]=(D[i][s]+D[i-1][s-j])%M;
	rep(test,0,t)
	{
		scanf(" %s",str);
		int sum=0;
		int n=strlen(str);
		rep(i,0,n)
			sum+=str[i]-'a';
		printf("%d\n",(D[n-1][sum]-1+M)%M);
	}
	return 0;
} 

/*
2
ya
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz


370640305
3320092814

*/