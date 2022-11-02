#include<bits/stdc++.h>
using namespace std;

int h,m,s,t1,t2;
int main()
{
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	t1=t1%12;
	t1=(t1*5)%60;
	t2=(t2*5)%60;
	bool chao1=false,chao2=false;
	chao2=(s!=0);
	h=(h*5+m/12)%60;
	chao1=(m%12!=0)||(chao2);
	bool bo1=true,bo2=true;	
	for (int i=t1;1;i=(i+1)%60)
	{
		if (i==s)	bo1=false;
		if (i==m && !chao2)	bo1=false;
		if (i==h && !chao1)	bo1=false;
		if (i==t2)	break;
		if (i==m && chao2)	bo1=false;
		if (i==h && chao1)	bo1=false;
	}
	for (int i=t2;1;i=(i+1)%60)
	{
		if (i==s)	bo2=false;
		if (i==m && !chao2)	bo2=false;
		if (i==h && !chao1)	bo2=false;
		if (i==t1)	break;
		if (i==m && chao2)	bo2=false;
		if (i==h && chao1)	bo2=false;
	}
	if (bo1 || bo2)	printf("yes\n");else printf("no\n");
	return 0;
}