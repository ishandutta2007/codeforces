#include <bits/stdc++.h>
using namespace std;
int T,n,d,x;bool fl;
int min(int x,int y) {return x<y?x:y;}
int max(int x,int y) {return x>y?x:y;} 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		fl=0;scanf("%d %d",&n,&d);if(d<=n) {puts("YES");continue;}
		x=floor(sqrt(d));
		for(int i=max(x-10,0);i<=min(x+10,d);++i)
			if(i+ceil(1.0*d/(i+1))<=n) {fl=1;puts("YES");break;}
		if(!fl) puts("NO"); 
	}
}