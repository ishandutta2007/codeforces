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

const int loop = 48;
const int mod  = 95542721;
const int MAXN = 100000 +10;
const int MAXT = (1<<18)+10;

int n,que;
int a[MAXN],lamp[MAXT],test[loop];
int t[MAXT][loop];

inline void update(int root, int L, int R){
	if (L!=R)
		lamp[root*2]= (lamp[root*2] + lamp[root]) % loop, 
		lamp[root*2+1]= (lamp[root*2+1] + lamp[root]) % loop;
	for (int i=0; i<loop; i++)
		test[(i-lamp[root]+loop)%loop] = t[root][i];
	for (int i=0; i<loop; i++)
		t[root][i] = test[i];
	lamp[root] = 0;
}

inline void build (int root, int lo, int hi){
	if (lo == hi){
		t[root][0] = a[lo] % mod;
		for (int i=1; i<loop; i++)
			t[root][i] = (LL)t[root][i-1] * (LL)t[root][i-1] % mod * (LL)t[root][i-1] % mod;
		return;
	}
	int mid = (lo+hi)/2;
	build(root*2,lo,mid);
	build(root*2+1,mid+1,hi);
	for (int i=0; i<loop; i++)
		t[root][i] = (t[root*2][i] + t[root*2+1][i]) % mod;
}

inline void go (int root, int L, int R, int lo, int hi){
	if (R<lo || hi<L){
		update(root,L,R);
		return;
	}
	if (lo<=L && R<=hi){
		lamp[root]++;
		update(root,L,R);
		return;
	}
	update(root,L,R);
	int mid = (L+R)/2;
	go(root*2,L,mid,lo,hi);
	go(root*2+1,mid+1,R,lo,hi);
	for (int i=0; i<loop; i++)
		t[root][i] = (t[root*2][i] + t[root*2+1][i]) % mod;
}

inline int get (int root, int L, int R, int lo, int hi, int past=0){
	if (R<lo || hi<L)
		return 0;
	if (lo<=L && R<=hi)
		return t[root][(past + lamp[root]) % loop];
	int mid = (L+R)/2;
	return (get(root*2,L,mid,lo,hi,past+lamp[root]) + get(root*2+1,mid+1,R,lo,hi,past+lamp[root])) % mod;
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	build(1,0,n-1);
	cin >> que;
	for (int o=0; o<que; o++){
		int type,lo,hi; cin >> type >> lo >> hi; 
		lo--; hi--;
		if (type == 1)
			cout << get(1,0,n-1,lo,hi) << endl;
		else
			go(1,0,n-1,lo,hi);
	}
	return 0;
}