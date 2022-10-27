#include<iostream>
#include<fstream>
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
#define inf 92233720368547757
#define mn 100005
#define FLN "test"

int n;
int board[15][15];
pair <int, int> place[105];

pair <int, int> Spath[15][15][5][105];
priority_queue <pair <pair <int, int>, pair <pair <int, int>, pair <int, int> > > > Q;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// freopen(FLN".inp", "r", stdin);
	// freopen(FLN".out", "w", stdout);
	
	for (int i1=0; i1<15; i1++) for (int i2=0; i2<15; i2++) for (int i3=0; i3<5; i3++) for (int i4=0; i4<105; i4++) Spath[i1][i2][i3][i4]={-1, -1};
		
	cin>>n;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)
	{
		cin>>board[i][j];
		place[board[i][j]]={i, j};
	}
	
	//BFS
	Spath[place[1].first][place[1].second][1][1]=Spath[place[1].first][place[1].second][2][1]=Spath[place[1].first][place[1].second][3][1]={0, 0};
	Q.push({{0, 0}, {place[1], {1, 1}}});
	Q.push({{0, 0}, {place[1], {2, 1}}});
	Q.push({{0, 0}, {place[1], {3, 1}}});
	
	vector <int> Km={1, 2, 2, 1, -1, 2, -2, 1, 1, -2, 2, -1, -1, -2, -2, -1}, Bm={1, 1, -1, 1, 1, -1, -1, -1};
	
	while (!Q.empty())
	{
		pair <pair <int, int>, pair <int, int> > t=Q.top().second;
		Q.pop();
		
		int x=t.first.first, y=t.first.second, z=t.second.first, u=t.second.second;
	//	cout<<x<<" "<<y<<' '<<z<<' '<<u<<'\n'<<Spath[x][y][z][u].first<<' '<<Spath[x][y][z][u].second<<'\n';
		
		if (t.second.second==n*n)
		{
			cout<<Spath[t.first.first][t.first.second][t.second.first][t.second.second].first<<' '<<Spath[t.first.first][t.first.second][t.second.first][t.second.second].second;
			return 0;
		}
		
		if (z==1) //ROOK
		{
			for (int i=1; i<=n; i++) if (i!=x)
			{
				if (board[i][y]==u+1)
				{
					if (Spath[i][y][z][u+1].first==-1 || (Spath[i][y][z][u+1].first==Spath[x][y][z][u].first+1 && Spath[i][y][z][u+1].second>Spath[x][y][z][u].second))
					{
						Spath[i][y][z][u+1]={Spath[x][y][z][u].first+1, Spath[x][y][z][u].second};
						Q.push({{-Spath[i][y][z][u+1].first, -Spath[i][y][z][u+1].second}, {{i, y}, {z, u+1}}});
					}
				}
				else if (Spath[i][y][z][u].first==-1 || (Spath[x][y][z][u].first+1==Spath[i][y][z][u].first && Spath[i][y][z][u].second>Spath[x][y][z][u].second))
				{
					Spath[i][y][z][u]={Spath[x][y][z][u].first+1, Spath[x][y][z][u].second};
					Q.push({{-Spath[i][y][z][u].first, -Spath[i][y][z][u].second}, {{i, y}, {z, u}}});
				}
			}
			for (int i=1; i<=n; i++) if (i!=y)
			{
				if (board[x][i]==u+1)
				{
					if (Spath[x][i][z][u+1].first==-1 || (Spath[x][i][z][u+1].second>Spath[x][y][z][u].second && Spath[x][i][z][u+1].first==Spath[x][y][z][u].first+1))
					{
						Spath[x][i][z][u+1]={Spath[x][y][z][u].first+1, Spath[x][y][z][u].second};
						Q.push({{-Spath[x][i][z][u+1].first, -Spath[x][i][z][u+1].second}, {{x, i}, {z, u+1}}});
					}
				}
				else if (Spath[x][i][z][u].first==-1 || (Spath[x][i][z][u].second>Spath[x][y][z][u].second && Spath[x][y][z][u].first+1))
				{
					Spath[x][i][z][u]={Spath[x][y][z][u].first+1, Spath[x][y][z][u].second};
					Q.push({{-Spath[x][i][z][u].first, -Spath[x][i][z][u].second}, {{x, i}, {z, u}}});
				}
			}
		}
		else if (z==2) //KNIGHTS
		{
			for (int i=0; i<Km.size(); i+=2) if (1<=x+Km[i] && x+Km[i]<=n && 1<=y+Km[i+1] && y+Km[i+1]<=n)
			{
				int X1=x+Km[i], Y1=y+Km[i+1];
				
				if (board[X1][Y1]==u+1)
				{
					if (Spath[X1][Y1][z][u+1].first==-1 || (Spath[X1][Y1][z][u+1].second>Spath[x][y][z][u].second && Spath[x][y][z][u].first+1==Spath[X1][Y1][z][u+1].first))
					{
						Spath[X1][Y1][z][u+1]={Spath[x][y][z][u].first+1, Spath[x][y][z][u].second};
						Q.push({{-Spath[X1][Y1][z][u+1].first, -Spath[X1][Y1][z][u+1].second}, {{X1, Y1}, {z, u+1}}});
					}
				}
				else if (Spath[X1][Y1][z][u].first==-1 || (Spath[X1][Y1][z][u].second>Spath[x][y][z][u].second && Spath[x][y][z][u].first+1==Spath[X1][Y1][z][u].first))
				{
					Spath[X1][Y1][z][u]={Spath[x][y][z][u].first+1, Spath[x][y][z][u].second};
					Q.push({{-Spath[X1][Y1][z][u].first, -Spath[X1][Y1][z][u].second}, {{X1, Y1}, {z, u}}});
				}
			}
		}
		else if (z==3)
		{
			for (int b=0; b<Bm.size(); b+=2)
			{
				for (int i=1; i<=n; i++)
				{
					int X1=x+i*Bm[b], Y1=y+i*Bm[b+1];
					if (X1<1 || X1>n || Y1<1 || Y1>n) break;
					
					if (board[X1][Y1]==u+1)
					{
						if (Spath[X1][Y1][z][u+1].first==-1 || (Spath[X1][Y1][z][u+1].second>Spath[x][y][z][u].second && Spath[x][y][z][u].first+1==Spath[X1][Y1][z][u+1].first))
						{
							Spath[X1][Y1][z][u+1]={Spath[x][y][z][u].first+1, Spath[x][y][z][u].second};
							Q.push({{-Spath[X1][Y1][z][u+1].first, -Spath[X1][Y1][z][u+1].second}, {{X1, Y1}, {z, u+1}}});
						}
					}
					else if (Spath[X1][Y1][z][u].first==-1 || (Spath[X1][Y1][z][u].second>Spath[x][y][z][u].second && Spath[X1][Y1][z][u].first==Spath[x][y][z][u].first+1))
					{
						Spath[X1][Y1][z][u]={Spath[x][y][z][u].first+1, Spath[x][y][z][u].second};
						Q.push({{-Spath[X1][Y1][z][u].first, -Spath[X1][Y1][z][u].second}, {{X1, Y1}, {z, u}}});
					}
				}
			}
		}
		
		//CHANGE PIECE
		for (int i=1; i<=3; i++) if (i!=z) if (Spath[x][y][i][u].first==-1 || (Spath[x][y][i][u].second>Spath[x][y][z][u].second+1 && Spath[x][y][z][u].first+1==Spath[x][y][i][u].first))
		{
			Spath[x][y][i][u]={Spath[x][y][z][u].first+1, Spath[x][y][z][u].second+1};
			Q.push({{-Spath[x][y][i][u].first, -Spath[x][y][i][u].second}, {{x, y}, {i, u}}});
		}
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_