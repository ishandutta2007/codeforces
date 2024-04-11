#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <time.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define abs(a) (a>0?a:-a)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
vector <int> vec;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	srand(unsigned(time(0)));
	for(int i=0;i<28;i++)
	{
		cout<<'?'<<' '<<(1LL*rand()*rand())%n+1<<endl;
		fflush(stdout);
		int x;
		cin>>x;
		vec.push_back(x);
	}
	sort(all(vec));
	int gcd=0;
	for(int i=0;i<27;i++)
	{
		gcd=__gcd(gcd,vec[i+1]-vec[i]);
	}
	int delta=gcd;
	int l=0,r=1e9,m,ans;
	while(l<=r)
	{
		m=l+r>>1;
		cout<<'>'<<' '<<m<<endl;
		fflush(stdout);
		int x;
		cin>>x;
		if(x==1)
		{
			l=m+1;
		}
		else
		{
			ans=m;
			r=m-1;
		}
	}
	cout<<'!'<<' '<<ans-delta*(n-1)<<' '<<delta<<endl;
	fflush(stdout);
	return 0;
}