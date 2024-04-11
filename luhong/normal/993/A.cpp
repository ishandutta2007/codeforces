#include<iostream>
#include<cstdio>
using namespace std;
bool mp[310][310];
int main()
{
	int a1,a2,b1,b2,c1,c2,d1,d2;scanf("%d%d%d%d%d%d%d%d",&a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2);
	int x=min(min(a1,b1),min(c1,d1));
	int X=max(max(a1,b1),max(c1,d1));
	int y=min(min(a2,b2),min(c2,d2));
	int Y=max(max(a2,b2),max(c2,d2));
	for(int i=x;i<=X;i++)
	for(int j=y;j<=Y;j++)mp[i+100][j+100]=1;
	scanf("%d%d%d%d%d%d%d%d",&a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2);
	x=min(min(a1,b1),min(c1,d1));
	X=max(max(a1,b1),max(c1,d1));
	y=min(min(a2,b2),min(c2,d2));
	Y=max(max(a2,b2),max(c2,d2));
	int w=0;int mid=x+X>>1;
	for(int i=y;i<=y+Y>>1;i++,w++)
		for(int j=mid-w;j<=mid+w;j++){if(mp[j+100][i+100])return 0*puts("YES");}
	w--;
	for(int i=y+Y>>1;i<=Y;i++,w--)
		for(int j=mid-w;j<=mid+w;j++){if(mp[j+100][i+100])return 0*puts("YES");}
	return 0*puts("NO");
}