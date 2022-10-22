#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<P, llint> T;

int kk, nn;
int Rank[200005];
int tmp[200005];

bool compare_sa(int i, int j)
{
	if(Rank[i] != Rank[j]) return Rank[i] < Rank[j];
	int ri, rj;
	if(i+kk <= nn) ri = Rank[i+kk]; else ri = -1;
	if(j+kk <= nn) rj = Rank[j+kk]; else rj = -1;
	return ri < rj;
}

//sa[0]sa[s.size()](s.size()+1)sa[0]
void makeSA(string s, int sa[]){
	nn = s.size();
	for(int i = 0; i <= nn; i++) sa[i] = i;
	for(int i = 0; i < nn; i++) Rank[i] = s[i];
	s += " ";
	s[nn] = -1;

	for(kk = 1; kk <= nn; kk*=2){
		sort(sa, sa+nn+1, compare_sa);
		int val = 0;
		tmp[sa[0]] = 0;
		for(int i = 1; i <= nn; i++){
			if(compare_sa(sa[i-1], sa[i])) val++;
			tmp[sa[i]] = val;
		}
		for(int i = 0; i <= nn; i++) Rank[i] = tmp[i];
	}
}

//lcp[i] = LCP(s.substr(sa[i]), s.substr(sa[i+1]))
void makeLCP(string s, int sa[], int lcp[]){
	nn = s.size();
	for(int i = 0; i <= nn; i++) Rank[sa[i]] = i;
	
	int h = 0;
	lcp[0] = 0;
	for(int i = 0; i < nn; i++){
		int j = sa[Rank[i]-1];
		while(i+h < nn && j+h < nn && s[i+h] == s[j+h]) h++;
		lcp[Rank[i]-1] = h;
		if(h > 0) h--;
	}
}

ll n;
string s, t;
int sa[200005], lcp[200005];
ll sum[200005];
ll l[200005], r[200005];
stack<P> stk;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s >> t;
	reverse(all(s));
	reverse(all(t));
	
	makeSA(s, sa);
	makeLCP(s, sa, lcp);
	
	rep(i, 1, n){
		sum[i] = sum[i-1];
		if(t[sa[i]] == '1') sum[i]++;
	}
	
	//rep(i, 1, n) cout << lcp[i] << " "; cout << endl;
	
	stk.push(P(-1, 0));
	rep(i, 1, n-1){
		while(stk.top().first >= lcp[i]) stk.pop();
		l[i] = stk.top().second+1;
		stk.push(P(lcp[i], i));
	}
	while(stk.size()) stk.pop();
	
	stk.push(P(-1, n));
	for(int i = n-1; i >= 1; i--){
		while(stk.top().first >= lcp[i]) stk.pop();
		r[i] = stk.top().second;
		stk.push(P(lcp[i], i));
	}
	
	//rep(i, 1, n-1) cout << l[i] << " " << r[i] << endl;
	
	ll ans = 0;
	rep(i, 0, n-1) if(t[i] == '0') chmax(ans, n-i);
	rep(i, 1, n-1){
		ll tmp = lcp[i] * (r[i] - l[i] + 1 - (sum[r[i]] - sum[l[i]-1]));
		chmax(ans, tmp);
	}
	cout << ans << endl;
	
	return 0;
}