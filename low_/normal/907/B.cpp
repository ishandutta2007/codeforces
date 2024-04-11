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

char board[10][10];

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	string ln;
	int ptr1=1, ptr2=1;
	for (int i=0; i<27; i++)
	{
		cin>>ln;
		
		board[ptr1][ptr2]=ln[0];
		board[ptr1][ptr2+1]=ln[1];
		board[ptr1][ptr2+2]=ln[2];
		ptr2+=3;
		if (ptr2>=10)
		{
			ptr1++;
			ptr2=1;
		}
	}
	int x, y;
	cin>>x>>y;
	
	int cnt=0;
	if (x%3==0 && y%3==0)
	{
		for (int i=7; i<=9; i++) for (int j=7; j<=9; j++) if (board[i][j]=='.') 
		{
			cnt++;
			board[i][j]='!';
		}
		if (cnt==0) for (int i=1; i<=9; i++) for (int j=1; j<=9; j++) if (board[i][j]=='.') board[i][j]='!';
	}
	else if (x%3==0 && y%3==1)
	{
		for (int i=7; i<=9; i++) for (int j=1; j<=3; j++) if (board[i][j]=='.') 
		{
			cnt++;
			board[i][j]='!';
		}
		if (cnt==0) for (int i=1; i<=9; i++) for (int j=1; j<=9; j++) if (board[i][j]=='.') board[i][j]='!';
	}
	else if (x%3==0 && y%3==2)
	{
		for (int i=7; i<=9; i++) for (int j=4; j<=6; j++) if (board[i][j]=='.') 
		{
			cnt++;
			board[i][j]='!';
		}
		if (cnt==0) for (int i=1; i<=9; i++) for (int j=1; j<=9; j++) if (board[i][j]=='.') board[i][j]='!';
	}
	else if (x%3==1 && y%3==0)
	{
		for (int i=1; i<=3; i++) for (int j=7; j<=9; j++) if (board[i][j]=='.') 
		{
			cnt++;
			board[i][j]='!';
		}
		if (cnt==0) for (int i=1; i<=9; i++) for (int j=1; j<=9; j++) if (board[i][j]=='.') board[i][j]='!';
	}
	else if (x%3==1 && y%3==1)
	{
		for (int i=1; i<=3; i++) for (int j=1; j<=3; j++) if (board[i][j]=='.') 
		{
			cnt++;
			board[i][j]='!';
		}
		if (cnt==0) for (int i=1; i<=9; i++) for (int j=1; j<=9; j++) if (board[i][j]=='.') board[i][j]='!';
	}
	else if (x%3==1 && y%3==2)
	{
		for (int i=1; i<=3; i++) for (int j=4; j<=6; j++) if (board[i][j]=='.') 
		{
			cnt++;
			board[i][j]='!';
		}
		if (cnt==0) for (int i=1; i<=9; i++) for (int j=1; j<=9; j++) if (board[i][j]=='.') board[i][j]='!';
	}
	else if (x%3==2 && y%3==0)
	{
		for (int i=4; i<=6; i++) for (int j=7; j<=9; j++) if (board[i][j]=='.') 
		{
			cnt++;
			board[i][j]='!';
		}
		if (cnt==0) for (int i=1; i<=9; i++) for (int j=1; j<=9; j++) if (board[i][j]=='.') board[i][j]='!';
	}
	else if (x%3==2 && y%3==1)
	{
		for (int i=4; i<=6; i++) for (int j=1; j<=3; j++) if (board[i][j]=='.') 
		{
			cnt++;
			board[i][j]='!';
		}
		if (cnt==0) for (int i=1; i<=9; i++) for (int j=1; j<=9; j++) if (board[i][j]=='.') board[i][j]='!';
	}
	else if (x%3==2 && y%3==2)
	{
		for (int i=4; i<=6; i++) for (int j=4; j<=6; j++) if (board[i][j]=='.') 
		{
			cnt++;
			board[i][j]='!';
		}
		if (cnt==0) for (int i=1; i<=9; i++) for (int j=1; j<=9; j++) if (board[i][j]=='.') board[i][j]='!';
	}
	
	for (int i=1; i<=9; i++) for (int j=1; j<=9; j++)
	{
		cout<<board[i][j];
		if (j%3==0) cout<<" ";
		if (j==9) 
		{
			cout<<"\n";
			if (i%3==0) cout<<"\n";
		}
	}
}