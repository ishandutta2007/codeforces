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

const int maxN = 100 * 1000 + 10;

int n;
int a[maxN],nex[maxN];
ll sum[maxN];

int main(){

	cin >> n;

	for (int i=1; i<=n; i++){ 
		cin >> a[i];
		int t=0;
		while (i+(1<<t) <= n) t++;
		nex[i] = t-1;
	}
	nex[n] = 0;

	for (int i=1; i<n; i++){
		int now = i;
		while (now<n){
			sum[now]+= a[i];
			now+= (1<<nex[now]);
		}
	}

	ll cur = 0;

	for (int i=1; i<n; i++){
		cur+= sum[i];
		cout << cur << endl;
	}
	
	return 0;
}