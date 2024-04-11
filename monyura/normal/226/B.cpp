#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
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
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
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
	int n;
	int A[100100];
	cin>>n;
	rep(i,0,n)
		scanf("%d",A+i);
	sort(A,A+n);
	ll S[100100]={0};
	S[0]=A[0];
	rep(i,1,n)
		S[i]=S[i-1]+A[i];
	ll K[100100];
	rep(k,1,n+1)
	{
		ll curr=0;
		ll cnt=1;
		for (ll j=n-2,mul=1;j>=0;j-=cnt,++mul)
		{
			cnt*=k;
			ll sum=S[j];
			if (j-cnt>=0) sum-=S[j-cnt];
			curr+=sum*mul;
			
		}
		K[k]=curr;
	}
	int q;
	cin>>q;
	rep(i,0,q)
	{
		int k;
		scanf("%d",&k);
		if (k>n) k=n;
		cout<<K[k]<<' ';
	}
	puts("");

}



int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
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