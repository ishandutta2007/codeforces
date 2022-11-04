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

const int maxN = 100000 + 10;

int n; 
int fen[maxN];
vector <ll> Q;
ll k;
ll sum[maxN];

void go (int pos){
	for (int i=pos; i<maxN; i+=(i&(-i))) 
		fen[i]++;
}

int get (int pos){
	int ret = 0;
	for (int i=pos; i>0; i-=(i&(-i)))
		ret+= fen[i];
	return ret;
}

bool valid (ll cost){
	memset(fen,0,sizeof fen);
	go(lower_bound(Q.begin(),Q.end(),0)-Q.begin()+1);
	ll ret = 0;
	for (int i=1; i<=n; i++){
		ret+= get(upper_bound(Q.begin(),Q.end(),sum[i]-cost)-Q.begin());
		go(lower_bound(Q.begin(),Q.end(),sum[i])-Q.begin()+1);
	}
	return ret>=k;
}

int main(){
	scanf("%d%I64d" , &n, &k);
	for (int i=1; i<=n; i++){
		int a; scanf("%d",&a); 
		sum[i] = sum[i-1]+a;
		Q.push_back(sum[i]);
	}
	Q.push_back(0);
	sort(Q.begin(),Q.end());
	Q.resize(unique(Q.begin(),Q.end())-Q.begin());
	ll lo=-(1ll<<47),hi=(1ll<<47),ans=0;
	while (lo<=hi){
		ll mid = (lo+hi)/2;
		if (valid(mid)){
			ans=mid; 
			lo=mid+1;
		}
		else
			hi=mid-1;
	}
	printf("%I64d\n",ans);
	return 0;
}