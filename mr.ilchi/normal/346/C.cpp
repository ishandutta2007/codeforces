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

const int MAXN = 1000000+10;

int n,a,b;
int x[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> x[i];
	cin >> b >> a;
	sort(x, x+n);
	n = unique(x, x+n) - x;
	int ret = 0;
	while (b>a){
		int less = 1;
		for (int i=n-1; i>=0; i--){
			if (b - b%x[i] >= a)
				less = max(less, b%x[i]);
			else{
				swap(x[i], x[n-1]);
				n--;
			}
		}
		ret++;
		b-=less;
		if (n==0){
			ret+= b-a;
			b = a;
			break;
		}
	}
	cout << ret << endl;
	return 0;
}