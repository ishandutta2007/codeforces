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

LL n,t;
LL C[50][50];

int main(){
	for (int i=0; i<50; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	cin >> n >> t;
	int k = -1;
	for (int i=0; i<60; i++) if (t == (1LL<<i)){
		k = i;
		break;
	}
	if (k == -1){
		cout << 0 << endl;
		return 0;
	}
	t = k+1;
	n++;
	if (t==1){
		for (int i=0; i<60; i++) if ((1LL<<i) > n){
			cout << max(0,i-1) << endl;
			break;
		}
		return 0;
	}
	vector <int> bit;
	LL temp = n;
	while (temp){
		bit.push_back(temp%2);
		temp/=2;
	}
	int Count = 0;
	LL ans = 0;
	for (int i=(int)bit.size()-1; i>=0; i--) if (bit[i]==1){
		if (Count > t)
			break;
		ans+= C[i][t-Count];
		Count++;
	}
	if (Count == t)
		ans++;
	cout << ans << endl;
	return 0;
}