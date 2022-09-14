#include<cstdio>
#include<algorithm>
using namespace std;
int Q;
int L[2<<17],R[2<<17];
main()
{
	scanf("%d",&Q);
	int l=0,r=0;
	for(;Q--;)
	{
		char c;
		int id;
		scanf(" %c%d",&c,&id);
		id--;
		if(c=='L')
		{
			L[id]=-l-1;
			R[id]=l;
			l++;
		}
		else if(c=='R')
		{
			L[id]=r;
			R[id]=-r-1;
			r++;
		}
		else
		{
			printf("%d\n",min(l+L[id],r+R[id]));
		}
	}
}