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
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef pair<int,int> pii;
typedef long double ldb;
typedef long long ll;

const int maxN= 100*1000 + 5;

int n,Q,root;
int par[maxN], dis[maxN], mini[maxN], maxi[maxN];
int lef[maxN], rig[maxN], cost[maxN];
int DP[3*maxN][25], beg[maxN];
ll dp[maxN];
vector <int> leaf, p, t;

inline void dfs (int v){

	if (lef[v]!=0){
		
		dfs (lef[v]);
		dfs (rig[v]);

		maxi[v]= maxi[rig[v]];
		mini[v]= mini[lef[v]];

		return;
	}

	maxi[v]= cost[v];
	mini[v]= cost[v];

	leaf.push_back (v);
}
/*******************************/
inline void setDyn (int v){
	
	if (v==0)
		return;

	if (par[v]!=-1){

		if (v==lef[par[v]])
			dp[v]= dp[par[v]] + mini[rig[par[v]]];
		else
			dp[v]= dp[par[v]] + maxi[lef[par[v]]];

		dis[v]= dis[par[v]] + 1;
	}

	setDyn (lef[v]);
	setDyn (rig[v]);
}
/*******************************/
inline bool cmp (const int &a1, const int &a2){
	
	return cost[a1] < cost[a2];
}
/*******************************/
inline int LCA (int a1, int a2){

	if (a1>a2)
		swap (a1,a2);
	
	int lg=0, pw=1;

	while (pw <= (a2-a1+1)){		
		lg ++;
		pw*=2;
	}		

	pw/=2;
	lg --;


	if (t[DP[a1][lg]] < t[DP[a2-pw+1][lg]])
		return p[DP[a1][lg]];

	return p[DP[a2-pw+1][lg]];
}
/*******************************/
inline int Find (int x){

	cost[0]= x;
	
	vector <int> :: iterator poi= lower_bound (leaf.begin(), leaf.end(), 0, cmp);

	if (poi==leaf.end())
		return leaf.back();

	if (poi==leaf.begin())
		return leaf[0];

	int now= *poi; poi--;
	int oth= *poi;

	return (cost[LCA(beg[now],beg[oth])] < x) ? now : oth;
}
/*******************************/
inline void DFS (int v){

	beg[v]= t.size();

	t.push_back (dis[v]);
	p.push_back (v);

	if (lef[v]==0)
		return;

	DFS (lef[v]);

	t.push_back (dis[v]);
	p.push_back (v);

	DFS (rig[v]);
	
	t.push_back (dis[v]);
	p.push_back (v);

}
/*******************************/
inline void RMQ (){
	
	for (int i=0; i<(int)t.size() ;i++)		
		DP[i][0]= i;

	int lg=1, pw=2;

	while (lg < 22){
		
		for (int i=0; i < (int)t.size() ;i++){ 

			if (i+pw/2 < (int)t.size()){

				int x1= DP[i][lg-1];
				int x2= DP[i+pw/2][lg-1];

				if (t[x1] < t[x2])
					DP[i][lg]= x1;
				else
					DP[i][lg]= x2;
			}

			else
				DP[i][lg]= DP[i][lg-1];
		}

		lg ++;
		pw*=2;
	}
}
/*******************************/
int main(){

	scanf ("%d", &n);

	for (int i=1;i<=n;i++){
			
		scanf ("%d%d", &par[i], &cost[i]);

		if (par[i]!=-1){
			
			if (lef[par[i]]==0)				
				lef[par[i]]= i;

			else{
				rig[par[i]]= i;
				if (cost[rig[par[i]]] < cost[lef[par[i]]])
					swap (rig[par[i]], lef[par[i]]);
			}
		}

		else
			root= i;
	}

	dfs (root);

	setDyn (root);

	DFS (root);

	RMQ ();

	sort (leaf.begin(), leaf.end(), cmp);

	scanf ("%d", &Q);

	while (Q){
		
		int tmp;

		scanf ("%d", &tmp);

		int pos= Find(tmp);

		cout << fixed << setprecision (12) << (long double)dp[pos]/(long double)dis[pos] << endl;

//		cerr << pos << endl;

		Q--;
	}

	return 0;
}