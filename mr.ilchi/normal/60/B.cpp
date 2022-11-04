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
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxN= 10+2;

bool mark[maxN][maxN][maxN];
char mat[maxN][maxN][maxN];
int k, n, m, yg, zg;

struct triple{
	int x,y,z;

	triple (int _x=-1, int _y=-1, int _z=-1) : x(_x), y(_y), z(_z) {}
};	
/**************************************/
inline void bfs (int x, int y, int z){
	queue <triple> Q;
	mark[x][y][z]= true;
	Q.push (triple (x,y,z));
	int cnt=0;
	int Move[6][3]= {{-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1}};
	while (!Q.empty()){
		triple top= Q.front(); Q.pop();
		for (int i=0;i< 6;i ++){
			x= top.x + Move[i][0], y= top.y + Move[i][1], z= top.z + Move[i][2];
			if (x<=0 || y<=0 || z<=0)
				continue;
			if (x>k || y>n || z>m)
				continue;

			if (!mark[x][y][z] && mat[x][y][z]!='#'){
				Q.push (triple (x,y,z));
				mark[x][y][z]= true;
			}
		}
		cnt ++;
	}
	cout << cnt << endl;
}
/**************************************/
int main(){
	cin >> k >> n >> m;
	for (int i=1;i<=k;i ++)
		for (int j=1;j<=n;j ++)
			for (int z=1;z<=m;z ++)
				cin >> mat[i][j][z];

	cin >> yg >> zg;
	bfs (1, yg, zg);

	return 0;
}