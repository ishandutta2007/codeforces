#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int n,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;;i++)
	{
		int k=((1<<i)-1)<<i-1;
		if(k>n) break;
		if(n%k==0) ans=k;
	}
	printf("%d\n",ans);
	
    return 0;
}