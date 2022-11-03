#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
int n;
int main()
{
    scanf("%d",&n);
    if(n==3) {
    	puts("1 1 3");return 0;
	}
	if(n==2)  {
    	puts("1 2");return 0;
	}
	if(n==1)  {
    	puts("1");return 0;
	}
	int t=1;
	while(1)
	{
		for(int i=1;i<=(n+1)/2;i++) printf("%d ",t);
		n=n-(n+1)/2;
		t*=2;
		if(n==3) {printf("%d %d %d",t,t,3*t); break;}
		if(n==2) {printf("%d %d",t,2*t); break;}
		if(n==1) {printf("%d",t); break;}
	}
    return 0;
}