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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 5000+10;
const int maxE = 100000+10;
const double eps = 1e-10;

int n,e,k;
int par[maxN];
vector <int> ans;

struct edge{
	int e1,e2,id;
	double w;
	edge(){}
	edge(int _e1,int _e2, int _id, double _w){
		e1=_e1 , e2=_e2, id=_id, w=_w;
		if(e1>e2) swap(e1,e2);
	}
	bool operator < (const edge &SEC) const{
		return (abs(w-SEC.w)>eps) ? (w<SEC.w) : (e1>SEC.e1);
	}
}yal[maxE],a[maxE];

int root (int x){
	return (par[x]!=x) ? (par[x]=root(par[x])) : (x);
}

int kruskal (double mid){
	for (int i=1; i<=e; i++){
		if (yal[i].e1 == 1)
			a[i] = edge(yal[i].e1,yal[i].e2,yal[i].id,yal[i].w+mid);
		else
			a[i] = yal[i];
	}
	sort(a+1,a+e+1);
	ans.clear();
	for (int i=1; i<=n; i++)
		par[i]=i;
	int ret = 0;
	for (int i=1; i<=e; i++) if (root(a[i].e1)!=root(a[i].e2)){
		par[root(a[i].e2)] = root(a[i].e1);
		ans.push_back(a[i].id);
		ret+= (a[i].e1==1);
	}
	if ((int)ans.size()<n-1)
		return -1;
	return ret;
}

int main(){
	scanf("%d%d%d" , &n, &e, &k);
	for (int i=1; i<=e; i++){
		int e1,e2,w; 
		scanf("%d%d%d" , &e1, &e2, &w);
		yal[i] = edge(e1,e2,i,w);
	}
	sort(yal+1,yal+e+1);
	for (int i=1; i<=e; i++){
		int j=i;
		while (j<=e && abs(yal[i].w-yal[j].w)<eps) j++;
		for (int k=i; k<j; k++)
			yal[i].w+= eps * (k-i);
		i=j-1;
	}
	double lo=-1e6,hi=1e6;
	for (int REP=1; REP<=70; REP++){
		double mid = (lo+hi)/2;
		int tmp = kruskal(mid);
		if (tmp == k){
			printf("%d\n" , n-1);
			for (int i=0; i<(int)ans.size(); i++)
				printf("%d " , ans[i]);
			printf("\n");
			return 0;
		}
		if (tmp<k)
			hi=mid;
		if (tmp>k)
			lo=mid;
	}
	printf("-1\n");

	return 0;
}