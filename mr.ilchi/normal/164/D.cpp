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

int start = clock();

const int MAXN = 1000+10;

bool mark[MAXN];
int n,k;
int x[MAXN],y[MAXN],len[MAXN],sz[MAXN],match[MAXN],d[MAXN];
int dis[MAXN][MAXN],adj[MAXN][MAXN],test[MAXN][MAXN];
vector <int> store,ans,have,ret;

struct cmp{
	bool operator () (const int &A , const int &B){
		return (d[A]!=d[B]) ? (d[A]>d[B]) : (A<B);
	}
};

bool BT (int poi, int pot){
	if (poi == (int)have.size())
		return true;
	int cur = have[poi];
	if (mark[cur])
		return BT(poi+1,pot);
	sz[cur] = 0;
	for (int i=0; i<len[cur]; i++) if (!mark[adj[cur][i]])
		test[cur][sz[cur]++] = adj[cur][i];
	if (sz[cur]==0)
		return BT(poi+1,pot);
	if (pot==0)
		return false;
	if (sz[cur]==1){
		mark[test[cur][0]] = true;
		if (BT(poi+1,pot-1)){
			ret.push_back(test[cur][0]);
			return true;
		}
		mark[test[cur][0]] = false;
		return false;
	}
	mark[cur] = true;
	if (BT(poi,pot-1)){
		ret.push_back(cur);
		return true;	
	}
	mark[cur] = false;
	if (pot<sz[cur])
		return false;
	for (int i=0; i<sz[cur]; i++)
		mark[test[cur][i]] = true;
	if (BT(poi+1,pot-sz[cur])){
		for (int i=0; i<sz[cur]; i++)
			ret.push_back(test[cur][i]);
		return true;
	}
	for (int i=0; i<sz[cur]; i++)
		mark[test[cur][i]] = false;
	return false;
}

bool go (int L){
	memset(len,0,sizeof len);
	set <int,cmp> SET;	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) if (i!=j && dis[i][j]>L)
			adj[i][len[i]++] = j;
		d[i] = len[i];
		if (d[i])
			SET.insert(i);
	}
	int pot = k;
	memset(mark,false,sizeof mark);
	ret.clear();
	while (pot>0 && !SET.empty() && d[*SET.begin()]>pot){
		pot--;
		int ind = *SET.begin(); SET.erase(ind);
		mark[ind] = true;
		ret.push_back(ind);
		for (int i=0; i<len[ind]; i++) if (!mark[adj[ind][i]]){
			SET.erase(adj[ind][i]);
			d[adj[ind][i]]--;
			SET.insert(adj[ind][i]);
		}
	}
	have.clear();
	memset(match,false,sizeof match);
	for (int i=1; i<=n; i++) if (!mark[i] && len[i]){
		for (int j=0; j<len[i]; j++) if (mark[adj[i][j]]){
			swap(adj[i][j],adj[i][len[i]-1]);
			len[i]--; j--;
		}
		for (int j=0; j<len[i] && !match[i]; j++) if (!match[adj[i][j]]){
			match[i] = adj[i][j];
			match[adj[i][j]] = i;
		}
		if (match[i])
			have.push_back(i);
	}
	if (pot < (int)have.size()/2)
		return false;
	if (pot>= (int)have.size()){
		ret.insert(ret.end(),have.begin(),have.end());
		return true;
	}
	for (int i=0; i<(int)have.size(); i++)
		for (int j=i+1; j<(int)have.size(); j++) if (len[have[i]] < len[have[j]])
			swap(have[i],have[j]);
//	random_shuffle(have.begin(),have.end());
	return BT(0,pot);
}

int main(){
	srand(12345678);
	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> x[i] >> y[i];
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			dis[i][j] = (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
			store.push_back(dis[i][j]);
		}
	}
	store.push_back(0);
	sort(store.begin(),store.end()); 
	store.resize(unique(store.begin(),store.end())-store.begin());
	int lo=0,hi=(int)store.size()-1;
	while (lo<=hi){
		int mid = (lo+hi)/2;
		if (go(store[mid])){
			ans=ret;
			hi=mid-1;
		}
		else
			lo=mid+1;
	}
	memset(mark,false,sizeof mark);
	for (int i=0; i<(int)ans.size(); i++) 
		mark[ans[i]] = true;
	for (int i=1; i<=n; i++) if (!mark[i] && (int)ans.size()<k)
		ans.push_back(i);
	sort(ans.begin(),ans.end());
	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i] << ' '; cout << endl;

	cerr << endl << endl << fixed << setprecision(3) << "TIME : " << (clock()-start+0.0) / CLOCKS_PER_SEC << endl;
	return 0;
}