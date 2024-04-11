#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

int m, n;
char board[55][55];
string dirs;
char mpp[4];
bool picked[4];

int x, y, ex, ey;
int ans=0;

void print()
{
	int tx=x, ty=y;
	
	for (int i=0; i<dirs.size(); i++)
	{
//		cerr<<tx<<" "<<ty<<"\n";
		if (mpp[dirs[i]-'0']=='L') ty--;
		if (mpp[dirs[i]-'0']=='R') ty++;
		if (mpp[dirs[i]-'0']=='U') tx--;
		if (mpp[dirs[i]-'0']=='D') tx++;
		
		if (ty<0 || ty>=m || tx<0 || tx>=n) return;
		if (board[tx][ty]=='#') return;
		if (ty==ey && tx==ex)
		{
			ans++;
			return;
		}
	}
}

void backtrack(int k)
{
	if (k==4) 
	{
//		cerr<<mpp[0]<<mpp[1]<<mpp[2]<<mpp[3]<<"\n";
		print();
//		cerr<<"\n";
		return;
	}
	
	if (!picked[0])
	{
		picked[0]=1;
		mpp[k]='L';
		backtrack(k+1);
		picked[0]=0;
	}
	if (!picked[1])
	{
		picked[1]=1;
		mpp[k]='R';
		backtrack(k+1);
		picked[1]=0;
	}
	if (!picked[2])
	{
		picked[2]=1;
		mpp[k]='U';
		backtrack(k+1);
		picked[2]=0;
	}
	if (!picked[3])
	{
		picked[3]=1;
		mpp[k]='D';
		backtrack(k+1);
		picked[3]=0;
	}
}

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	cin>>n>>m;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) 
	{
		cin>>board[i][j];
		if (board[i][j]=='S')
		{
			x=i;
			y=j;
		}
		if (board[i][j]=='E')
		{
			ex=i;
			ey=j;
		}
	}
	
	cin>>dirs;
	
	backtrack(0);
	
	cout<<ans;
}