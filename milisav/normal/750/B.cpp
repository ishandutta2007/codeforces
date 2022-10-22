#include <iostream>
#include <cstring>
int n;
int t;
int x;
char s[50];
bool pos;
int main()
{
	scanf("%d",&n);
	pos=true;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		scanf("%s",s);
		if(s[0]=='N')
		{
			x-=t;
		}
		if(s[0]=='S')
		{
			x+=t;
		}
		if(x<0 || x>20000) pos=false;
		if((s[0]=='E' || s[0]=='W') && (x==0 || x==20000)) pos=false;
	}
	if(x!=0) pos=false;
	if(pos) printf("YES");
	else printf("NO");
	return 0;
}