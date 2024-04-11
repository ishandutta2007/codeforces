#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;
#define h 500
#define sz 999
#define cnt 666
#define x first
#define y second
pair<int,int> pos[cnt+5];
int quad[4],d[][2]={{1,1},{-1,1},{1,-1},{-1,-1}};
void send()
{
	printf("%d %d\n",pos[0].x,pos[0].y);
	fflush(stdout);
	int p,nx,ny;
	scanf("%d%d%d",&p,&nx,&ny);
	assert(p!=0);
	if (p==-1)
	exit(0);
	pos[p]={nx,ny};
}
bool nok()
{
	for (int i=1;i<=cnt;i++)
	{
		if (pos[0]==pos[i])
		return 1;
	}
	return 0;
}
int main()
{
	for (int i=0;i<=cnt;i++)
	scanf("%d%d",&pos[i].x,&pos[i].y);
	while (pos[0].x>h)
	{
		pos[0].x--;
		send();
	}
	while (pos[0].x<h)
	{
		pos[0].x++;
		send();
	}
	while (pos[0].y>h)
	{
		pos[0].y--;
		send();
	}
	while (pos[0].y<h)
	{
		pos[0].y++;
		send();
	}
	for (int i=1;i<=cnt;i++)
	{
		quad[0]+=(pos[i].x<h && pos[i].y<h);
		quad[1]+=(pos[i].x>h && pos[i].y<h);
		quad[2]+=(pos[i].x<h && pos[i].y>h);
		quad[3]+=(pos[i].x>h && pos[i].y>h);
	}
	int ans=0;
	for (int i=1;i<4;i++)
	{
		if (quad[i]<quad[ans])
		ans=i;
	}
	while (1)
	{
		pos[0].x+=d[ans][0];
		pos[0].y+=d[ans][1];
		if (nok())
		pos[0].y-=d[ans][1];
		send();
	}
}