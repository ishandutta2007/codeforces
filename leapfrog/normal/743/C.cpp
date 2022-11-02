//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
int n;
int main()
{
	scanf("%d",&n);
	if(n==1) return puts("-1"),0;
	else return printf("%d %d %d\n",n,n+1,n*(n+1)),0;
}