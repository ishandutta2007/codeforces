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
typedef pair<int,int> pii;
typedef complex<double> point;

const int MAXN = 100000+10;
const int MAXT = (1<<18)+5;
const int inf = 1000000000;

int n;
int l[MAXN],v[MAXN],r[MAXN];
int lef[MAXN],rig[MAXN];
int all[MAXT],maxi[MAXT],ffpos[MAXT];
vector <int> del[MAXN];

inline void go (int root, int lo, int hi, int L, int R, int val){
	if (ffpos[root] == -1)
		ffpos[root] = lo;
	if (R<lo || hi<L)
		return;
	if (L<=lo && hi<=R){
		all [root]+= val;
		maxi[root]+= val;
		return;
	}
	int mid = (lo + hi) / 2;
	go (root*2, lo, mid, L, R, val);
	go(root*2+1,mid+1,hi,L, R, val);
	if (maxi[root*2] >= maxi[root*2+1]){
		maxi[root] = maxi[root*2] + all[root];
		ffpos[root] = ffpos[root*2];
	}else{
		maxi[root] = maxi[root*2+1] + all[root];
		ffpos[root] = ffpos[root*2+1];
	}
}

pii get (int root, int lo, int hi, int L, int R){
	if (hi<L || R<lo)
		return pii(-inf, -1);
	if (L<=lo && hi<=R)
		return pii(maxi[root], ffpos[root]);
	int mid = (lo+hi)/2;
	pii ll = get(root*2, lo, mid, L, R);
	pii rr = get(root*2+1,mid+1,hi,L,R);
	return ll>rr ? pii(ll.first+all[root], ll.second) : pii(rr.first+all[root], rr.second);
}

int main(){
	cin >> n;
	vector <pii> Q;
	for (int i=0; i<n; i++){
		cin >> l[i] >> v[i] >> r[i];
		Q.push_back(pii(v[i], i));
	}
	sort(Q.begin(), Q.end());
	int ret = 0;
	int pl = 0, pr = 0;
	memset(ffpos, -1, sizeof ffpos);
	for (int i=0; i<(int)Q.size(); i++){
		for (int j=0; j<(int)del[i].size(); j++){
			int pos = del[i][j];
			go(1, 0, n-1, lef[Q[pos].second], pos, -1);
			go(1, 0, n-1, pos, pos, -inf);
		}
		int index = Q[i].second;
		lef[index] = lower_bound(Q.begin(), Q.end(), pii(l[index], -1)) - Q.begin();
		rig[index] = upper_bound(Q.begin(), Q.end(), pii(r[index]+1,-1))- Q.begin();
		pii temp = get(1, 0, n-1, lef[index], i);
		if (ret < temp.first+1){
			ret = temp.first+1;
			pl = temp.second;
			pr = i;
		}
		go(1, 0, n-1, lef[index], i, 1);
		del[rig[index]].push_back(i);
	}
	pl = max(pl, 0);
	pr = max(pr, 0);
	vector <int> ans;
	for (int i=pl; i<=pr; i++){
		int index = Q[i].second;
		if (l[index]<=v[Q[pl].second] && v[Q[pr].second]<=r[index])
			ans.push_back(index+1);
	}
	sort(ans.begin(), ans.end());
	cout << ret << endl;
	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}