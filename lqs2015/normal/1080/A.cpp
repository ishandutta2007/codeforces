#include<bits/stdc++.h>
using namespace std;
int n,k,a,b,c;
int main()
{
	scanf("%d%d",&n,&k);
	a=2*n;b=5*n;c=8*n;
	printf("%d\n",(a+k-1)/k+(b+k-1)/k+(c+k-1)/k);
	return 0;
}