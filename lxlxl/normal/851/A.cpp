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
#define inf 1e9
using namespace std;

int n,m,k;

int main()
{
	int t; scanf("%d%d%d",&n,&k,&t);
	if(t<=k) printf("%d\n",t);
	else if(t<=n) printf("%d\n",k);
	else printf("%d\n",n+k-t);
	
	return 0;
}