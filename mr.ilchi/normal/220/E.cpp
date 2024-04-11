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
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100000+10;

bool mark[MAXN];
int n,N;
int a[MAXN],f1[MAXN],lef[MAXN],rig[MAXN];
ll k;

int get (int pos, int *fen){
	int ret=0;
	for (int i=pos; i; i-=(i&(-i)))
		ret+= fen[i];
	return ret;
}

void add (int pos, int *fen, int cost){
	for (int i=pos; i<=N; i+=(i&(-i)))
		fen[i]+=cost;
}	

int main(){
	cin >> n >> k;
	vector <int> store;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		store.push_back(a[i]);
	}
	sort(store.begin(),store.end());
	store.resize(unique(store.begin(),store.end())-store.begin());
	N = (int)store.size();
	for (int i=1; i<=n; i++)
		a[i] = lower_bound(store.begin(),store.end(),a[i])-store.begin() + 1;
	ll inv = 0;
	for (int i=1; i<=n; i++){
		inv+= (i-1-get(a[i],f1));
		add(a[i],f1,1);
	}
	int R=-1;
	ll cur = inv, ans=0;
	for (int i=1; i<=n; i++)
		add(a[i],rig,1);
	for (int i=1; i<n; i++){
		if (R<=i){
			R = i+1;
			cur = inv;
		}
		else{
			cur+= (i-1-get(a[i],lef));
			cur+= (get(a[i]-1,rig));
		}
		add(a[i],lef,1);
		if (!mark[i])
			add(a[i],rig,-1);
		if (cur<=k){
			ans+= (n-R+1);
			continue;
		}
		while (R<=n && cur>k){
			cur-= (i-get(a[R],lef));
			cur-= get(a[R]-1,rig);
			add(a[R],rig,-1);
			mark[R] = true;
			R++;
		}
		if (R==n+1)
			break;
		ans+= (n-R+1);
	}
	cout << ans << endl;
	return 0;
}