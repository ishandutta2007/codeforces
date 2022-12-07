#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,x;
int e[100010];
template <class T1,class T2>inline void gmax(T1 &a,T2 b){if(b>a)a=b;}  
template <class T1,class T2>inline void gmin(T1 &a,T2 b){if(b<a)a=b;}  
int main()
{
	scanf("%d",&n);
	int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d",&x);
		e[x] = e[x - 1] + 1;
		gmax(ans, e[x]);
	}
	printf("%d\n",n - ans);
	
	return 0;
}