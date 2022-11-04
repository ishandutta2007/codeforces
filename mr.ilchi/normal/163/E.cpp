/*
 * in the name of god
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
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXL=1000000+10;
const int MAXT=1<<21;

bool vis[MAXL];
int n,que,number,N=1;
int nex[MAXL],lo[MAXL],hi[MAXL],ind[MAXL],val[MAXL];
int child[MAXL][26];
ll all[MAXT];
vector <int> adj[MAXL];

void go (const int &root, const int &st, const int &fn, const int &lo, const int &hi, const int &cost){
	if (hi<st || fn<lo)
		return;
	if (lo<=st && fn<=hi){
		all[root]+= cost;
		return;
	}
	int mid = (st+fn)/2;
	go(root*2,st,mid,lo,hi,cost);
	go(root*2+1,mid+1,fn,lo,hi,cost);
}

ll get (int root, int st, int fn, const int &pos){
	ll ret = 0;
	while (true){
		ret+= all[root];
		if (st==fn)
			break;
		int mid = (st+fn)/2;
		if (pos<=mid)
			root=root*2,fn=mid;
		else
			root=root*2+1,st=mid+1;
	}
	return ret;
}

void dfs (int v){
	number++;
	lo[v] = hi[v] = number;
	for (int i=0; i<(int)adj[v].size(); i++){
		dfs(adj[v][i]);
		hi[v] = max(hi[v],hi[adj[v][i]]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> que >> n;
	for (int i=1; i<=n; i++){
		string s; cin >> s;
		int cur = 1;
		for (int j=0; j<(int)s.size(); j++){
			if (child[cur][s[j]-'a']==0)
				child[cur][s[j]-'a'] = ++N;
			cur = child[cur][s[j]-'a'];
		}
		val[cur]++;
		ind[i]=cur;
		vis[i]=true;
	}
	queue <int> Q;
	nex[1] = 1;
	for (int i=0; i<26; i++) if (child[1][i]){
		nex[child[1][i]] = 1;
		Q.push(child[1][i]);
	}
	while (!Q.empty()){
		int front = Q.front(); Q.pop();
		for (int i=0; i<26; i++) if (child[front][i]){
			int cur = nex[front];
			while (cur!=1 && child[cur][i]==0)
				cur = nex[cur];
			if (child[cur][i]!=0)
				cur = child[cur][i];
			nex[child[front][i]] = cur;
			Q.push(child[front][i]);
		}
	}
	for (int i=2; i<=N; i++)
		adj[nex[i]].push_back(i);
	dfs(1);
	for (int i=1; i<=N; i++)
		go(1,1,N,lo[i],hi[i],val[i]);
	for (int o=1; o<=que; o++){
		char ord; cin >> ord;
		if (ord=='+'){
			int x; cin >> x;
			if (!vis[x])
				go(1,1,N,lo[ind[x]],hi[ind[x]],val[ind[x]]);
			vis[x] = true;
		}
		if (ord=='-'){
			int x; cin >> x;
			if (vis[x])
				go(1,1,N,lo[ind[x]],hi[ind[x]],-val[ind[x]]);
			vis[x] = false;
		}
		if (ord=='?'){
			string s; cin >> s;
			int cur=1;
			ll  ans=0;
			for (int j=0; j<(int)s.size(); j++){
				while (cur!=1 && child[cur][s[j]-'a']==0)
					cur = nex[cur];
				if (child[cur][s[j]-'a'])
					cur = child[cur][s[j]-'a'];
				ans+= get(1,1,N,lo[cur]);
			}
			cout << ans << endl;
		}
	}
	return 0;
}