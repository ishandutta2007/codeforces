/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int dx[] = {-1,-1,-1,0,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,0,1,-1,0,1};

bool mark[10][10],test[10][10];
char mat[10][10];
int n=8;

inline bool go(){
	
	mark[8][1] = true;

	while (true){

		int cnt = 0;

		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) if (mark[i][j])
				cnt++;

		if (cnt==0)
			return false;
		
		if (mark[1][8])
			return true;

		memset (test,false,sizeof test);

		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) if (mat[i][j]!='S'){
				for (int z=0; z<9; z++){
					int x = i + dx[z];
					int y = j + dy[z];
					if (mark[x][y])
						test[i][j] = true; 
				}
			}

		for (int i=n+1; i>0; i--)
			for (int j=n; j>0; j--) if (mat[i-1][j] == 'S'){
				mat[i][j] = 'S';
				mat[i-1][j] = '.';
			}

		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) if (mat[i][j] == 'S')
				test[i][j] = false;

		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				mark[i][j] = test[i][j];
	}

	return false;
}

int main(){
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			cin >> mat[i][j];

	if (go())
		cout << "WIN" << endl;
	else
		cout << "LOSE" << endl;

	return 0;
}