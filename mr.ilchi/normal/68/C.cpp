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
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int n, res, pool=-1;
int enter[10];
int mini[10][10], maxi[10][10], act[10][10];

struct node{
	int a[7], cost;

}test;
vector <node> Q[10][30];
/********************************/
inline void Set (int v, int cur){
	if (cur>n){
		int sum= 0, cost=0;
		for (int i=(v+1);i<=n;i++) if(test.a[i]){
			sum += test.a[i];
			cost+= act[v][i] + (test.a[i]*test.a[i]); 
		}

		test.cost= cost;

		Q[v][sum].push_back (test);
		return;
	}

	for (int i=mini[v][cur]; i<=maxi[v][cur] ;i++){
		test.a[cur]= i;
		Set (v,cur+1);
	}
}
/********************************/
inline void init(){
	for (int i=1;i<n;i++)
		Set(i,(i+1));
}
/********************************/
inline void btrack (int v, int val){
	if (v==n){
		res = enter[n];
		pool= max (pool, val); 
		return;
	}

	if (v==1){
		for (int i=0;i<30;i++){
			for (int j=0;j< (int)Q[1][i].size();j++){
				node &tmp= Q[1][i][j];
				for (int z=2;z<=n;z++)
					enter[z]+= tmp.a[z];
				btrack (v+1, tmp.cost);
				for (int z=2;z<=n;z++)
					enter[z]-= tmp.a[z];
			}
			if (pool!=-1)
				break;
		}
		return;
	}

	for (int i=0;i< (int)Q[v][enter[v]].size();i++){
		node &tmp= Q[v][enter[v]][i];
		for (int j=(v+1);j<=n;j++)
			enter[j]+= tmp.a[j];
		btrack (v+1, val + tmp.cost);
		for (int j=(v+1);j<=n;j++)
			enter[j]-= tmp.a[j];
	}
}
/********************************/
int main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		for (int j=(i+1);j<=n;j++){
			int s,e; cin>>s>>e;
			cin >> mini[s][e] >> maxi[s][e];
			cin >> act [s][e];
		}
	}

	init ();

	btrack(1,0);

	if (pool!=-1)
		cout << res << ' ' << pool << endl;
	else
		cout << -1 << ' ' << -1 << endl;

	return 0;
}