#include<iostream>
#include<algorithm>
using namespace std;
struct Cut
{
	int wx,wy,hx,hy;
	bool In(int x,int y,int xx,int yy)
	{
		if (wx==hx)
		{
			return (wx>x && wx<xx && y==wy && yy==hy);
		}
		else 
		{
			return (wy>y && wy<yy && x==wx && xx==hx);
		}
	}
	void input() 
	{
		cin>>wx>>wy>>hx>>hy;
	}
}cuts[111];
int w,h,n,area[111],t;
bool used[111];
void dfs(int x,int y,int xx,int yy)
{
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		if (cuts[i].In(x,y,xx,yy)) 
		{
			used[i]=1;
			if (cuts[i].wx==cuts[i].hx)
			{
				dfs(x,y,cuts[i].hx,yy);
				dfs(cuts[i].wx,y,xx,yy);
			}
			else
			{
				dfs(x,y,xx,cuts[i].hy);
				dfs(x,cuts[i].wy,xx,yy);
			}
			return;
		}
	}
	area[t++]=(xx-x)*(yy-y);
}
int main()
{
	cin>>w>>h>>n;
	for (int i=1;i<=n;i++) 
	cuts[i].input();
	dfs(0,0,w,h);
	sort(area,area+t);
	for (int i=0;i<t;i++) cout<<area[i]<<" ";
	cout<<endl;
	return 0;
}