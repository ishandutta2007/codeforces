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
ll k[maxN],b[maxN];

struct node{
	ll a,b;
	int t;
	node () {}
	node(ll _a, ll _b, int _t){
		a = _a;
		b = _b;
		if (b<0){
			a=-a;
			b=-b;
		}
		t = _t;
	}
	bool operator < (const node &SEC) const{
		// a/b < SEC.a/SEC.b;
		return a * SEC.b < b * SEC.a;
	}
};

int main(){
	
	cin >> n;

	vector <node> Q;

	ll MUL=0 , SUM=0;

	for (int i=1; i<=n; i++){
		cin >> k[i] >> b[i];
		if (k[i] == 0){
			i--; n--;
			continue;
		}
		if (k[i]>0){
			Q.push_back(node(-b[i],k[i],i));
		}
		else{
			Q.push_back(node(-b[i],k[i],i));
			MUL+= k[i];
			SUM+= b[i];
		}
	}

	sort(Q.begin(),Q.end());

	ll pm = MUL;
	ll ps = SUM;

	int ans = 0;

	for (int i=0; i<(int)Q.size(); i++){
		
		int j = i;

		while (j<(int)Q.size() && (!(Q[i]<Q[j])) && (!(Q[j]<Q[i]))){
		
			int ind = Q[j].t;

			if (k[ind]>0){
				SUM+= b[ind];
				MUL+= k[ind];
			}
			if (k[ind]<0){
				SUM-= b[ind];
				MUL-= k[ind];
			}
			j++;
		}

		i = j-1;

		ans+= (pm != MUL);

		ps = SUM;
		pm = MUL;
	}

	cout << ans << endl;

	return 0;
}