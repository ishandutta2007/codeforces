#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

int m, n, rowcheck[55], colcheck[55];
char board[55][55];
bool kq=1;

void bfs(int R)
{
	queue <pair <char, int> > Q;
	set <int> col, row;
	for (int j=1; j<=m; j++) if (board[R][j]=='#') 
	{
		if (col.count(j)==0) Q.push({'C', j});
		col.insert(j);
	}
	int t;
	while (!Q.empty())
	{
		t=Q.front().second;
		if (Q.front().first=='C')
		{
			Q.pop();
			for (int i=1; i<=n; i++) if (board[i][t]=='#')
			{
				if (row.count(i)==0) Q.push({'R', i});
				row.insert(i);
			}
		}
		else 
		{
			Q.pop();
			for (int j=1; j<=m; j++) if (board[t][j]=='#') 
			{
				if (col.count(j)==0) Q.push({'C', j});
				col.insert(j);
			}
		}
	}
	
	for (int i: row) for (int j: col) if (board[i][j]!='#') kq=0;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>n>>m;
	for (int j=1; j<=m; j++) colcheck[j]=0;
	for (int i=1; i<=n; i++) 
	{
		for (int j=1; j<=m; j++) cin>>board[i][j];
		rowcheck[i]=0;
	}
	
	vector <int> col, row;
	
	for (int i=1; i<=n; i++) if (rowcheck[i]==0)
	{
		bfs(i);
	}
	
	if (kq) cout<<"Yes";
	else cout<<"No";
}