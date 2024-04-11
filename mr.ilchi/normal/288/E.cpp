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

const int MAXN= 100000+10;
const int mod = 1000000007;

int n;
LL p[MAXN],p4[MAXN],p7[MAXN];
string l,r;

struct node{
	int cnt,sum,res,F,S;
	node () {}
	node (int cnt, int sum, int res, int F, int S) : cnt(cnt), sum(sum), res(res), F(F), S(S) {}
	void print(){
		cout << "node : " << cnt << ' ' << sum << ' ' << res << ' ' << F << ' ' << S << endl;
	}
}f1[MAXN],f2[MAXN],f3[MAXN];	

node calc (LL A, node B){
	A%=mod;
	return node(B.cnt, (A*B.cnt + B.sum)%mod, ((A*A%mod*(B.cnt-1)%mod) + B.res + A * (B.sum - B.S) + A * (B.sum - B.F)) % mod, (int)((A+B.F)%mod), (int)((A+B.S)%mod)); 
}

node go (const string &s, int poi){
	LL cur = (LL)(s[poi]-'0') * p[n-1-poi] % mod;
	for (int j=poi+1; j<(int)s.size(); j++){
		if (s[poi]==s[j]){
			node t1 = go(s, j);
			node t2 = (s[poi]=='4') ? (f2[n-j]) : (f1[n-j]);
			node t12= node((t1.cnt + t2.cnt)%mod, (t1.sum + t2.sum)%mod, (t1.res + t2.res)%mod, (s[poi]=='4') ? (t1.F) : (t2.F), (s[poi]=='4') ? (t2.S) : (t1.S));
			node ret= calc(cur, t12);
			ret.res = (ret.res + ((4LL*p[n-1-j] + p7[n-1-j])%mod * ((7LL*p[n-1-j]+p4[n-1-j]) % mod))%mod) % mod; 
			return ret;
		}
		cur = ((LL)cur + (s[j]-'0') * p[n-1-j]) % mod;
	}
	return node(1, cur, 0, cur, cur);
}

int main(){
	cin >> l >> r;
	n = (int)l.size();
	p[0] = 1;
	for (int i=1; i<MAXN; i++){
		p[i] = p[i-1] * 10LL % mod;
		p4[i]= (p4[i-1] * 10LL + 4) % mod;
		p7[i]= (p7[i-1] * 10LL + 7) % mod;
	}
	
	f1[1] = node(1, 4, 0,4,4);
	f2[1] = node(1, 7, 0,7,7);
	f3[1] = node(2,11,28,4,7);

	for (int i=2; i<=n; i++){
		f1[i] = calc(4LL*p[i-1], f3[i-1]);
		f2[i] = calc(7LL*p[i-1], f3[i-1]);
		f3[i] = node((f1[i].cnt+f2[i].cnt)%mod, (f1[i].sum + f2[i].sum)%mod, (f1[i].res + f2[i].res + (4LL*p[i-1]+p7[i-1])%mod * ((7LL*p[i-1]+p4[i-1])%mod)) % mod, p4[i], p7[i]);
	}
	
	for (int i=0; true; i++) if (l[i]!=r[i]){
		LL cur = 0;
		for (int j=0; j<i; j++)
			cur = (cur + p[n-1-j] * (l[j]-'0')) % mod;
		cout << (((LL)calc(cur, go(l, i)).res + calc(cur, go(r,i)).res + (cur+4LL*p[n-1-i]+p7[n-1-i])%mod * ((cur+7LL*p[n-1-i]+p4[n-1-i])%mod) % mod) + mod) % mod << endl;
		break;
	}
	return 0;
}