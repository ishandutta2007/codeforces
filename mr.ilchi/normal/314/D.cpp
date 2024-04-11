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
typedef pair<LL,LL> pLL;

const int MAXN = 100000+10;

int n;
LL minL[MAXN],maxL[MAXN];
LL minR[MAXN],maxR[MAXN];
pLL a[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; i++){
		LL x,y; cin >> x >> y;
		x<<=1, y<<=1;
		a[i] = pLL(x-y, x+y);
	}
	sort(a, a+n);
	for (int i=0; i<n; i++){
		minL[i] = (i==0) ? (a[i].second) : (min(minL[i-1], a[i].second));
		maxL[i] = (i==0) ? (a[i].second) : (max(maxL[i-1], a[i].second));
	}
	for (int i=n-1; i>=0; i--){
		minR[i] = (i==n-1) ? (a[i].second) : (min(minR[i+1], a[i].second));
		maxR[i] = (i==n-1) ? (a[i].second) : (max(maxR[i+1], a[i].second));
	}
	LL lo = 0, hi = (1LL<<40), ans = (1LL<<40);
	while (lo<=hi){
		LL mid = (lo+hi)/2;
		int poi = 0;
		bool f = false;
		for (int i=0; i<n; i++){
			while (poi<n && a[i].first + 2*mid >= a[poi].first) poi++;
			LL mini = (1LL<<60), maxi = -(1LL<<60);
			if (i!=0) {   mini = min(mini, minL[i-1]); maxi = max(maxi, maxL[i-1]); }
			if (poi!=n) { mini = min(mini, minR[poi]); maxi = max(maxi, maxR[poi]); }
			if (mini + 2 * mid >= maxi){
				f = true;
				break;
			}
		}
		if (f){
			ans = mid;
			hi = mid-1;
		}else
			lo = mid+1;
	}
	cout << (ans/2) << ((ans%2) ? (".5") : ("")) << endl;
	return 0;
}