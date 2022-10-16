/*
	author:		MarX
	school:		UH
*/

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef pair<char,char> pcc;
typedef pair<int,int> pii;
typedef pair<pcc,int> ppi;
typedef vector<int> vi;
typedef long long  LL;

#define MAX 10000

int r,c;

char M[200][200];
char W[200][200];
bool P[200][200];
char L[] = {'B','W'};

void DFS(int i, int j, int mode)
{
	if (0 <= i && i < r && 0 <= j && j < c && !P[i][j] && W[i][j] == '.')
	{
		M[i][j] = L[mode];
		P[i][j] = true;
		DFS(i + 1,j, 1 - mode);
		DFS(i - 1,j, 1 - mode);
		DFS(i,j + 1, 1 - mode);
		DFS(i,j - 1, 1 - mode);
	}
}

int main()
{
	scanf("%d%d",&r,&c);
	for (int i = 0; i < r; ++i)
		scanf("%s",W[i]);

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (W[i][j] == '.' && !P[i][j])
				DFS(i,j,0);

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (W[i][j] == '.')
				printf("%c",M[i][j]);
			else
				printf("-");
		}
		printf("\n");
	}
}