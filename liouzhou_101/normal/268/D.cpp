#include<iostream>

using namespace std;

const int MOD=1000000009;

int n,h,ans;
int F[2][32][32][32],G[2][32][32][32];

inline void add(int &x,int y)
{
	x+=y;
	if (x>=MOD) x-=MOD;
}

int main()
{
	cin>>n>>h;
	F[1][1][1][1]=4;
	for (int i=1;i<n;++i)
	{
		int pre=i&1;
		int now=pre^1;
		for (int x=1;x<=h;++x)
			for (int y=x;y<=h;++y)
				for (int z=y;z<=h;++z)
				{
					int tx=min(x+1,h),ty=min(y+1,h),tz=min(z+1,h);
					{
					int &t=F[pre][x][y][z];
					if (t)
					{
						add(F[now][tx][ty][tz],t);
						add((x<h)?F[now][1][ty][tz]:G[now][1][ty][tz],t);
						add((y<h)?F[now][1][tx][tz]:G[now][1][tx][tz],t);
						add((z<h)?F[now][1][tx][ty]:G[now][1][tx][ty],t);
						t=0;
					}
					}
					{
					int &t=G[pre][x][y][z];
					if (t)
					{
						add(G[now][tx][ty][tz],t);
						add((x<h)?F[now][ty][tz][h]:G[now][ty][tz][h],t);
						add((y<h)?F[now][tx][tz][h]:G[now][tx][tz][h],t);
						add((z<h)?F[now][tx][ty][h]:G[now][tx][ty][h],t);
						t=0;
					}
					}
				}
	}
	for (int x=1;x<=h;++x)
		for (int y=x;y<=h;++y)
			for (int z=y;z<=h;++z)
			{
				add(ans,F[n&1][x][y][z]);
				if (x<h) add(ans,G[n&1][x][y][z]);
			}
	cout<<ans<<endl;
	return 0;
}