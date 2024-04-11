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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 200000+10;
const int MAXT = (1<<19)+10;
const int mod = 1000000000;

int n,que;
int comb0[MAXN],comb1[MAXN],sum[MAXN];
int d0[MAXT],d1[MAXT],all[MAXT];

inline int shift (int A, int B, int C){
	return ((LL)A * comb0[C] + (LL)B * comb1[C]) % mod;
}

inline void assign (int root, int lo, int hi, int pos, int val){
	if (lo == hi){
		val-=all[root];
		d0[root] = d1[root] = (val+mod) % mod;
		return;
	}
	int mid = (lo + hi) / 2;
	if (pos<=mid){
		assign(root*2,lo,mid,pos,(val-all[root])%mod);
	}else
		assign(root*2+1,mid+1,hi,pos,(val-all[root])%mod);
	d0[root] = ((LL)d0[root*2] + shift(d0[root*2+1], d1[root*2+1], mid-lo+1) + (LL)all[root] * sum[hi-lo]) % mod;
	d1[root] = ((LL)d1[root*2] + shift(d0[root*2+1], d1[root*2+1], mid-lo+2) + (LL)all[root] * (sum[hi-lo+1]-1)) % mod;
}

inline pii get (int root, int lo, int hi, int L, int R){
	if (L<=lo && hi<=R)
		return pii(d0[root], d1[root]);
	int mid = (lo + hi) / 2;
	if (R<=mid)
		return get(root*2, lo, mid, L, R);
	if (L>mid)
		return get(root*2+1, mid+1, hi, L, R);
	pii t0 = get(root*2, lo, mid, L, R);
	pii t1 = get(root*2+1, mid+1, hi, L, R);
	return pii(((LL)t0.first + shift(t1.first, t1.second, mid-max(lo,L)+1) + (LL)all[root]*sum[min(R,hi)-max(lo,L)])%mod, 
			   ((LL)t0.second+ shift(t1.first, t1.second, mid-max(lo,L)+2) + (LL)all[root]*(sum[min(R,hi)-max(lo,L)+1]-1))%mod); 
}

inline void go (int root, int lo, int hi, int L, int R, int val){
	if (R<lo || hi<L)
		return;
	if (L<=lo && hi<=R){
		all[root]+= val;
		d0 [root] = (d0[root] + (LL)val * sum[hi-lo]) % mod;
		d1 [root] = (d1[root] + (LL)val * (sum[hi-lo+1]-1)) % mod;
		return;
	}
	int mid = (lo + hi) / 2;
	go(root*2,lo,mid,L,R,val);
	go(root*2+1,mid+1,hi,L,R,val);
	d0[root] = ((LL)d0[root*2] + shift(d0[root*2+1], d1[root*2+1], mid-lo+1) + (LL)all[root] * sum[hi-lo]) % mod;
	d1[root] = ((LL)d1[root*2] + shift(d0[root*2+1], d1[root*2+1], mid-lo+2) + (LL)all[root] * (sum[hi-lo+1]-1)) % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	comb0[0] = 1, comb1[0] = 0;
	comb0[1] = 0, comb1[1] = 1;
	sum[0] = 1, sum[1] = 2;
	for (int i=2; i<MAXN; i++){
		comb0[i] = (comb0[i-1] + comb0[i-2]) % mod;
		comb1[i] = (comb1[i-1] + comb1[i-2]) % mod;
		sum[i] = ((LL)sum[i-1] + (comb0[i] + comb1[i]) % mod) % mod;
	}
	cin >> n >> que;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		assign(1,0,n-1,i,temp);
	}
	for (int o=0; o<que; o++){
		int ord; cin >> ord;
		if (ord == 1){
			int pos, val; cin >> pos >> val;
			pos--;
			assign(1,0,n-1,pos,val);
		}else if (ord == 2){
			int lo,hi; cin >> lo >> hi; 
			lo--; hi--;
			cout << (get(1,0,n-1,lo,hi).first+mod)%mod << endl;
		}else if (ord == 3){
			int lo,hi,val; cin >> lo >> hi >> val; 
			lo--; hi--;
			go(1,0,n-1,lo,hi,val);
		}else
			assert(false);
	}
	return 0;
}