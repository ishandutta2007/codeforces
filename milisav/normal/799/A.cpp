#include <bits\stdc++.h>
using namespace std;
int n,t,k,d;
int m;
int main()
{
	scanf("%d %d %d %d",&n,&t,&k,&d);
	m=d/t;
	m++;
	m=m*k;
	if(m>=n) printf("NO");
	else printf("YES");
	return 0;
}