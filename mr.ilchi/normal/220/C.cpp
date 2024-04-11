/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100000+10;

int n;
int a[MAXN],b[MAXN],pos[MAXN],t[MAXN];
vector <int> change[MAXN];

struct cmp{
	bool operator () (const int &A, const int &B){
		return (t[A]!=t[B]) ? (t[A]<t[B]) : (A<B);
	}
};

int myabs(int x) { return (x<0) ? (-x) : x; }

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i=1; i<=n; i++)
		cin >> b[i];
	set <int, cmp> lef,rig;
	int ans = n+1;
	for (int i=1; i<=n; i++){
		ans = min(ans, myabs(i-pos[b[i]]));
		if (i<=pos[b[i]]){
			t[i] = i-pos[b[i]]+1;
			lef.insert(i);
			change[i+1].push_back(i);
			change[i+n-pos[b[i]]+1].push_back(i);
		}
		else{
			t[i] = i-pos[b[i]]+1;
			change[t[i]].push_back(i);
			change[i+1].push_back(i);
			rig.insert(i);
		}
	}
	cout << ans << endl;
	set <int,cmp> :: iterator it;
	for (int rep=2; rep<=n; rep++){
		for (int i=0; i<(int)change[rep].size(); i++){
			int x = change[rep][i];
			if (lef.find(x)!=lef.end()){
				lef.erase(x);
				t[x] = n-pos[b[x]]+rep;
				rig.insert(x);
			}
			else{
				rig.erase(x);
				t[x] = rep;
				lef.insert(x);
			}
		}
		int cur = n+1;
		if (!lef.empty()){
			it = lef.end(); it--;
			cur = min(cur, rep-t[(*it)]);
		}
		if (!rig.empty()){
			it = rig.begin(); 
			cur = min(cur, t[(*it)]-rep);
		}
		cout << cur << endl;
	}
	return 0;
}