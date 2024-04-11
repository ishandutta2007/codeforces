#include <bits/stdc++.h>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
int T,n,x,y;
int main()
{
	scanf("%d",&T);
	while(T--) scanf("%d %d %d",&n,&x,&y),printf("%d\n",max(n-x,n-y)+1); 
}