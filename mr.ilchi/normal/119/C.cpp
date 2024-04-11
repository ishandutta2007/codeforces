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
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <cstring>
#include <fstream>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef complex<double> point;

const int maxN = 50 + 5;
const int maxS = 100+ 5;

int n,m,k;
ll  dp [maxN][maxN][maxS];

struct node{
	
	ll a,b;
	
	int c,id;

	node () {}

	node (ll a , ll b , int c , int id) : a(a) , b(b) , c(c) , id(id) {}

	inline bool operator < (const node &sec) const{
		
		return c<sec.c;
	}

};

vector <node> Q;

inline ll median (ll a , ll b , ll c){
	
	if (a>=min(b,c) && a<=max(b,c)) return a; 
	if (b>=min(a,c) && b<=max(a,c)) return b; 
	return c; 
}

inline void print (int x , int y , int z){
	
	dp[x][y][z] -= (Q[x].a + z);

	if (dp[x][y][z] == 0){
		cout << "YES" << endl;
		cout << Q[x].id << ' ' << Q[x].a + z << endl;
		return;
	}

	ll val = Q[x].a + z;
	
	for (int f=0; f<x; f++) if (Q[f].c<Q[x].c){
					
		if (val%k==0 && median(val/k,Q[f].a,Q[f].b)==val/k)
			if (dp[f][y-1][val/k-Q[f].a] == dp[x][y][z]){
				print (f , y-1 , val/k-Q[f].a);
				break;
			}
					
		if (median(val-k,Q[f].a,Q[f].b) == val-k)
			if (dp[f][y-1][val-k-Q[f].a] == dp[x][y][z]){
				print (f , y-1 , val-k-Q[f].a);
				break;
			}
	}

	cout << Q[x].id << ' ' << Q[x].a + z << endl;
}

int main(){

	cin >> n >> m >> k;

	for (int i=1; i<=m; i++){

		node tmp;

		cin >> tmp.a >> tmp.b >> tmp.c;

		tmp.id = i;

		Q.push_back (tmp);
	}

	sort (Q.begin() , Q.end());

	for (int i=0; i<m; i++){
		node now = Q[i];
		for (int j=1; j<=n; j++){
			for (ll diff = now.b-now.a; diff>=0; diff--){
				ll val = now.a + diff;
				for (int z=0; z<i; z++) if (Q[z].c<Q[i].c){
					
					if (val%k==0 && median(val/k,Q[z].a,Q[z].b)==val/k)
						dp[i][j][diff] = max (dp[i][j][diff] , dp[z][j-1][val/k-Q[z].a]);
					
					if (median(val-k,Q[z].a,Q[z].b) == val-k)
						dp[i][j][diff] = max (dp[i][j][diff] , dp[z][j-1][val-k-Q[z].a]);
				}

				if (dp[i][j][diff]>0)
					dp[i][j][diff]+= now.a + diff;

				if (j==1)
					dp[i][j][diff] = now.a + diff;
			}
		}
	}

	ll res = 0;

	int x=0,y=0,z=0;

	for (int i=0; i<m; i++)
		for (ll diff = Q[i].b - Q[i].a; diff>=0; diff--) if (dp[i][n][diff]>res){
			
			res = dp[i][n][diff];

			x = i , y = n , z = diff;
		}

	if (res!=0ll)
		print (x,y,z);

	else
		cout << "NO" << endl;

	return 0;
}