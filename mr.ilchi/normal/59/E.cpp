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
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxN= 3000+5;

bool mark[maxN][maxN];
int n,e,k;
int flag[maxN];
int dis [maxN][maxN];
vector <int> adj[maxN];
vector <int> no[maxN][maxN];

struct node{
	int p,v;

	node (int _p=-1, int _v=-1) : p(_p), v(_v) {}

}par[maxN][maxN];
/***************************************/
inline void bfs (){
	for (int i=1;i<= n;i ++)
		mark[i][1]= true;
	queue <node> Q;
	Q.push (node(1,1));
	dis[1][1]= 0;
	int cnt=0, ent=0;
	while (Q.size() && (ent==0)){
		cnt ++;
		node top= Q.front();
		Q.pop ();
		int v= top.v, p= top.p;
		int Dis= dis[p][v];
		for (int i=0;i< (int)no[p][v].size();i ++){
			flag[no[p][v][i]]= cnt;
		}
		for (int i=0;i< (int)adj[v].size();i ++){
			int tmp= adj[v][i];
			if (flag[tmp]!=cnt && !mark[v][tmp]){
				mark[v][tmp]= true;
				par [v][tmp]= top;
				dis [v][tmp]= Dis+1;
				Q.push (node(v,tmp));
				if (tmp==n)
					ent= v;
			}		
		}
	}
	if (ent==0){
		printf ("-1\n");
		return;
	}
	node cur= node (ent,n);
	printf ("%d\n", dis[ent][n]);
	vector <int> path;
	while (cur.v!=1){
		path.push_back (cur.v);
		cur= par[cur.p][cur.v];
	}
	path.push_back (1);
	for (int i=(int)path.size()-1;i>= 0;i --)
		printf ("%d ", path[i]);
	printf ("\n");
}
/***********************************/
int main(){
	scanf ("%d%d%d", &n, &e, &k);
	for (int i=1;i<= e;i ++){
		int x,y;
		scanf ("%d%d", &x, &y);
		adj[x].push_back (y);
		adj[y].push_back (x);
	}
	for (int i=1;i<= k;i ++){
		int a,b,c;
		scanf ("%d%d%d", &a, &b, &c);
		no[a][b].push_back (c);
	}
	
	bfs ();

	return 0;
}