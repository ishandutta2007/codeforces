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

int n;
int ul,ur,dl,dr,tot;

int go (int x, int ul, int ur, int dl, int dr, int key){

	int less = min (x,ur); ur-=less; x -= less;
		less = min (x,ul); ul-=less; x -= less;
		less = min(ur,dr); ur-=less; dr-= less;

	return key * (ul + dl - ur - dr);
}

int main(){

	cin >> n;
	for (int i=1; i<=n; i++){
		string s; cin >> s;
		if (s=="UL") ul++;
		if (s=="UR") ur++;
		if (s=="DL") dl++;
		if (s=="DR") dr++;
		if (s=="ULDR") tot++;
	}

	ll ans = 0;

	for (int i=-n; i<=n; i++){

		bool f = false;

		if (i<0){
			f = true;
			i = -i;
			swap(ul,dl);
			swap(ur,dr);
		}

		if (i > ul + ur){
			ans+= max(0,tot-(i-ul-ur)+1);
			if (f){
				i = -i;
				swap(ul,dl);
				swap(ur,dr);
			}
			continue;
		}

		int lef = go(i,ul,ur,dl,dr,-1);
		int rig = go(i,ur,ul,dr,dl,+1);

		ans+= ((rig-lef)/2 + 1 + max(0,tot));

		if (f){
			i = -i;
			swap(ul,dl);
			swap(ur,dr);
		}
	}

	cout << ans << endl;

	return 0;
}