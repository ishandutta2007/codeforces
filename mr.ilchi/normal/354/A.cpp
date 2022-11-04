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

int n,l,r,ql,qr;
LL a[1<<20], sum[1<<20];
LL ans = (1LL<<60);

void check(){
	sum[0] = a[0];
	for (int i=1; i<n; i++)
		sum[i] = sum[i-1] + a[i];
	ans = min(ans, l * sum[n-1] + ql * (n-1));
	LL cur = l * a[0];
	for (int i=1, j=n-1; i<=j; i++, j--){
		cur+= r * a[j];
		if (i!=j){
			cur+= l * a[i];
			ans = min(ans, cur + ((LL)sum[j-1] - sum[i]) * (LL)l + (LL)ql * (j-i-1));
		}else
			ans = min(ans, cur);
	}
	if (n==1)
		ans = min(ans, l * a[0]);
}

int main(){
	cin >> n >> l >> r >> ql >> qr;
	for (int i=0; i<n; i++)
		cin >> a[i];
	check(); 
	reverse(a, a+n); swap(l,r); swap(ql, qr);
	check();
	cout << ans << endl;
	return 0;
}