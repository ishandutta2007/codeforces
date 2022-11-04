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
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxG= 2000;
const int maxN= 1000*100 + 5;
const int maxT= 1000*1000 + 5;
const int maxQ= 1000*100 + 5;

int n,Q,len,cntg;
int l[maxQ] , r[maxQ];
int comp[maxN] , a[maxN], b[maxN] , res[maxN] , mark[maxN]; 
ll cost [maxG] , maxi[maxG];
vector <int> group[maxG];
vector <int> query[maxT] , inv[maxT];

inline void update (int t){
	
	for (int i=0; i<cntg; i++)
		cost[i]= a[maxi[i]] + (ll)b[maxi[i]]*t;

	for (int i=0; i<(int)inv[t].size(); i++) if (mark[inv[t][i]]!=(t+1)){
		
		int x= inv[t][i];

		mark[x]= t+1;

		ll tmp= a[x] + (ll)b[x]*t;

		if ((cost[comp[x]]<tmp) || (cost[comp[x]]==tmp && x<maxi[comp[x]])) { cost[comp[x]]= tmp; maxi[comp[x]]=x; }
	}
}
/************************************/
inline void answer (int l, int r, int t, int pos){

	res[pos]=l;

	ll now = a[l] + (ll)b[l]*t;

	for (int i=l+1; i<=r && comp[i]==comp[l]; i++){
		ll tmp= a[i] + (ll)b[i]*t;
		if (now < tmp) { now = tmp; res[pos]= i; }
	}

	if (comp[r]==comp[l]) return;

	for (int i=comp[l]+1; i<comp[r]; i++){
		ll tmp= a[maxi[i]] + (ll)b[maxi[i]]*t;
		if (now<tmp) { now = tmp; res[pos]= maxi[i]; }
	}

	for (int i=comp[r]*len+1; i<=r; i++){
		ll tmp= a[i] + (ll)b[i]*t;
		if (now < tmp) { now = tmp; res[pos]= i; }
	}

	return;
}
/************************************/
int main(){
	
	scanf ("%d%d", &n, &Q);

	for (int i=1;i<=n;i++) scanf ("%d%d", &a[i], &b[i]);

	len= (int)sqrt((double)n);

	for (int i=1;i<=n;i++){
		comp[i] = (i-1)/len;
		group[comp[i]].push_back (i);
	}

	cntg= comp[n] + 1;

	for (int i=0;i<cntg;i++){

		for (int j=0;j<(int)group[i].size();j++)	
			for (int z=j+1;z<(int)group[i].size();z++){

				int e1=group[i][j] , e2=group[i][z];

				if (a[e2]<=a[e1]){
					
					if (b[e1] < b[e2]){
						int pos = (a[e1]-a[e2]+b[e2]-b[e1])/(b[e2]-b[e1]);
						if (pos < maxT)
							inv[pos].push_back (e2);
					}
				}

				else{

					if (b[e2] < b[e1]){
						int pos = (a[e2]-a[e1]+b[e1]-b[e2]-1)/(b[e1]-b[e2]);
						if (pos < maxT)
							inv[pos].push_back (e1);
					}
				}
			}
	}

	for (int i=0; i<cntg; i++){
		maxi[i]= group[i][0];
		for (int j=1;j<(int)group[i].size();j++) if (a[maxi[i]] < a[group[i][j]]) maxi[i]= group[i][j]; 
	}

	for (int i=1; i<=Q; i++){
		int t;
		scanf ("%d%d%d", &l[i],&r[i],&t);
		query[t].push_back (i);
	}

	for (int i=0; i<maxT; i++){
		
		update (i);

		for (int j=0; j<(int)query[i].size(); j++)
			answer (l[query[i][j]] , r[query[i][j]] , i, query[i][j]);
	}

	for (int i=1; i<=Q; i++) printf ("%d\n", res[i]);

	return 0;
}