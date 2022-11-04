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

int n,que;
LL fen[4][(1<<11)+10][500+10];

inline LL get (int type, int root, int lo, int hi, int x, int y, LL cost){
	if (lo>x)
		return 0LL;
	if (hi<=x){
		LL ret = 0;
		for (int cur=y; cur; cur-=(cur&(-cur)))
			ret^= (fen[type][root][cur] & cost);
		return ret;
	}
	int mid = (lo + hi) / 2;
	return get(type,root*2,lo,mid,x,y,cost) ^ get(type,root*2+1,mid+1,hi,x,y,cost);
}

inline void go (int type, int root, int lo, int hi, int x, int y, LL cost){
	if (x < lo || x > hi)
		return;
	for (int cur=y; cur<=n/2+1; cur+=(cur&(-cur)))
		fen[type][root][cur]^=cost;
	if (lo == hi)
		return;
	int mid = (lo + hi) / 2;
	if (x<=mid)
		go(type, root*2, lo, mid, x, y, cost);
	else
		go(type, root*2+1, mid+1, hi, x, y, cost);
}

#define type(x,y) ((x)%2*2 + (y)%2) 

inline LL _get (int x, int y){
	return get(type(x,y), 1, 1, n/2+1, (x+1)/2, (y+1)/2, (1LL<<62)-1); 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> que;
	for (int o=0; o<que; o++){
		int type; cin >> type;
		int x,y,xx,yy; cin >> x >> y >> xx >> yy;
		if (type == 1){
			LL ret = 0;
			ret+= _get(xx,yy) ^ _get(xx,y-1) ^ _get(x-1,yy) ^ _get(x-1,y-1);
			cout << ret << endl;
		}else{
			LL v; cin >> v;
			go(type(x,y), 1, 1, n/2+1, (x+1)/2, (y+1)/2, v);
			go(type(xx+1,y), 1, 1, n/2+1, (xx+2)/2, (y+1)/2, v);
			go(type(x,yy+1), 1, 1, n/2+1, (x+1)/2, (yy+2)/2, v);
			go(type(xx+1,yy+1), 1, 1, n/2+1, (xx+2)/2, (yy+2)/2, v);
		}
	}
	return 0;
}