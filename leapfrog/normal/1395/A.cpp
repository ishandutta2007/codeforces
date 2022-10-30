#include<bits/stdc++.h>
using namespace std;
int T,r,g,b,w;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d%d",&r,&g,&b,&w);
		if(r%2+g%2+b%2+w%2<=1) {puts("Yes");continue;}else if(!r||!g||!b) {puts("No");continue;}
		r--,g--,b--,w+=3;if(r%2+g%2+b%2+w%2<=1) puts("Yes");else puts("No");
	}
	return 0;
}