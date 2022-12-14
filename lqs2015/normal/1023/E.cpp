#include<bits\stdc++.h>
using namespace std;
int n,x,y;
bool mp[555][555];
string s;
int main()
{
	scanf("%d",&n);
	mp[1][1]=1;x=y=1;
	while(x+y<=n)
	{
		printf("? %d %d %d %d\n",x+1,y,n,n);
		fflush(stdout);
		cin>>s;
		if (s=="YES") x++;
		else y++;
		mp[x][y]=1;
	}
	x=y=n;
	mp[n][n]=1;
	while(x+y>n+1)
	{
		printf("? %d %d %d %d\n",1,1,x,y-1);
		fflush(stdout);
		cin>>s;
		if (s=="YES") y--;
		else x--;
		mp[x][y]=1;
	}
	x=y=1;
	printf("! ");
	while(x+y<2*n)
	{
		if (mp[x+1][y]) 
		{
			printf("D");
			x++;
		}
		else 
		{
			printf("R");
			y++;
		}
	}
	printf("\n");
	return 0;
}