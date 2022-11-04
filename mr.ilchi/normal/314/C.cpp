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

const int MAXN = 100000+10;
const int mod = 1000000007;

int n,maxi;
int a[MAXN],fen[1<<20];

inline int get (int pos){
	int ret = 0;
	for (int i=pos; i; i-=(i&(-i)))
		ret = (ret + fen[i]) % mod;
	return ret;
}

inline void add (int pos, int cost){
	for (int i=pos; i<=maxi; i+=(i&(-i)))
		fen[i] = (fen[i] + cost) % mod;
}
	
int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	maxi = *max_element(a, a+n);
	for (int i=n-1; i>=0; i--){
		int f1 = get(maxi);
		int f2 = get(a[i]);
		int f3 = get(a[i]-1);
		add(a[i], ((LL)a[i] * ((LL)f1-f3+1) - ((LL)f2-f3)) % mod); 
	}
	cout << (get(maxi) + mod) % mod << endl;
	return 0;
}