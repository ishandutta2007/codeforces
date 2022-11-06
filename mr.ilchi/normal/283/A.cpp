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

const int MAXN = 200000+10;

int que;
LL a[MAXN],add[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> que;
	int n = 1;
	LL sum = 0;
	cout << fixed << setprecision(10);
	for (int i=0; i<que; i++){
		int t; cin >> t;
		if (t==1){
			int a, x; cin >> a >> x;
			sum+= (LL)a * x;
			add[a-1]+= x;
		}else if (t==2){
			int k; cin >> k;
			a[n++] = k;
			sum+= k;
		}else{
			if (n!=1)
				add[n-2]+= add[n-1];
			sum-=(a[n-1] + add[n-1]); 
			add[n-1] = 0;
			n--;
		}
		cout << ((long double)sum) / n << endl;
	}
	return 0;
}