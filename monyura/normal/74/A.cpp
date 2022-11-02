#include <cstdio>
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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);
const ld Eps=1e-8;

template<class T> inline T sqr(T a){return a*a;}

int main()
{
	int n;
	cin>>n;
	int A[7];
	char name[1000];
	char best[1000]={0};
	ll mx=-1e9;
	rep(i,0,n)
	{
		scanf(" %s",name);
		rep(j,0,7)
			scanf("%d",A+j);
		ll sum=A[0]*100-A[1]*50;
		rep(j,2,7)
			sum+=A[j];
		if (sum>mx)
		{
			mx=sum;
			strcpy(best,name);
		}
	}
	printf("%s\n",best);
	return 0;
}
/*
4
4 5 9 13
//4
4 2 1 3 4
//4
4
4 8 12 20
//4
3
1 2 4
//2
5
3 8 1 5 2
//5
4
2 1 3 4
*/