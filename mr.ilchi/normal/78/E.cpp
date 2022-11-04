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
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

bool mark[20][20], flag[1000];
char mat1[20][20], mat2[20][20], now[20][20];
int n,boom;
int par[300], dp[300];
int cost[300][300], dis[300][300];
vector <int> adj[1000];

int move[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

struct pii{
	int x,y;

	pii (int x=-1, int y=-1) : x(x), y(y) {}
};
vector <pii> Q  [1000];
/******************************************/
inline pii decode (int id){
	if (id%n==0)
		return pii (id/n, n);

	return pii (id/n + 1, id%n);
}
/*****************************************/
inline int code (int x, int y){
	return n*(x-1) + y;
}
/*****************************************/
inline void update (){
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (now[i][j]=='H'){
			
			for (int z=0;z<4;z++){
				
				int ii= i+move[z][0];
				int jj= j+move[z][1];

				if (now[ii][jj]=='D')
					now[i][j] = 'C';
			}	
		}

	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)	if (now[i][j]=='C')
			now[i][j]= 'D';
}
/*****************************************/
inline void bfs (int x, int y){

	for (int i=1;i<=n;i++)
		memset (mark[i], false, sizeof mark[i]);

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			
			if (mat1[i][j]=='Z')
				now [i][j]= 'D';

			else if (mat1[i][j]=='Y')
				now [i][j]= 'B';

			else
				now [i][j]= 'H';
		}
	}

	if (now[x][y]=='B' || now[x][y]=='D')
		return;

	int root= code(x,y);

	Q[0].push_back (pii(x,y)); dis[root][root]= 0; mark[x][y]= true;

	for (int i=0; Q[i].size() ; i++){
		
		for (int j=0;j<(int)Q[i].size();j++){
			
			pii &cur= Q[i][j];

			if (now[cur.x][cur.y]!='H')
				continue;

			for (int z=0;z<4;z++){
				
				int xx= cur.x + move[z][0];
				int yy= cur.y + move[z][1];

				if (!mark[xx][yy] && now[xx][yy]=='H'){
					
					Q[i+1].push_back (pii(xx,yy));
					mark[xx][yy]= true;
					dis [root][code(xx,yy)]= i+1;		
				}
			}
		}

		Q[i].clear();
		update();
	}
}
/*****************************************/
inline bool isPath(){
	
	queue <int> Q;

	memset (flag, false, sizeof flag);
	
	Q.push (0); flag[0]= true; par[0]= -1; dp[0]= 1000;

	while (!Q.empty() && !flag[201]){

		int top= Q.front(); Q.pop();

		for (int i=0;i<(int)adj[top].size();i++){
			
			int tmp= adj[top][i];

			if (cost[top][tmp]>0 && !flag[tmp]){
				
				flag[tmp]= true;
				par [tmp]= top;
				dp  [tmp]= min (cost[top][tmp],dp[top]);

				Q.push (tmp);
			}
		}
	}

	return flag[201];
}
/*****************************************/
inline int maxFlow (){
	
	int ret=0;

	while (isPath()){
		
		ret+= dp[201];

		int cur= 201;

		while (cur!=0){
			
			int p= par[cur];

			cost[p][cur]-= dp[201];
			cost[cur][p]+= dp[201];

			cur= p;
		}
	}

	return ret;
}
/*****************************************/
int main(){

	scanf ("%d%d", &n, &boom);

	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf (" %c", &mat1[i][j]);
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf (" %c", &mat2[i][j]);
	
	for (int i=0;i<110;i++)
		for (int j=0;j<110;j++)
			dis[i][j]= 1000;

	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			bfs (i,j);

	vector <int> sc, lb;

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){ 
			if (mat1[i][j]>='1' && mat1[i][j]<='9'){
				sc.push_back (code(i,j));
			}
			if (mat2[i][j]>='1' && mat2[i][j]<='9'){
				lb.push_back (100 + code(i,j));
			}
		}
	}

	for (int i=0;i<(int)sc.size();i++){
		
		pii now= decode(sc[i]);
		cost[0][sc[i]]= mat1[now.x][now.y]-'0';
		adj[0].push_back (sc[i]);
		adj[sc[i]].push_back (0);

		for (int j=0;j<(int)lb.size();j++) if (dis[sc[i]][lb[j]-100]<=boom){

			adj[sc[i]].push_back (lb[j]);
			adj[lb[j]].push_back (sc[i]);
			
			cost[sc[i]][lb[j]] = 1000;

			now= decode(lb[j]-100);

			cost[lb[j]][201]= mat2[now.x][now.y]-'0';

		}
	}

	for (int j=0;j<(int)lb.size();j++){
		adj[lb[j]].push_back (201);
		adj[201].push_back (lb[j]);
	}

	cout << maxFlow() << endl;
	
	return 0;
}