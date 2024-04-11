#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=100000;

int slen;
string s;
string ans;

string add(const string &a,const string &b) {
	string ret(max(SZ(a),SZ(b)),'?');
	for(int i=0,c=0;i<SZ(a)||i<SZ(b)||c!=0;++i) {
		if(i<SZ(a)) c+=a[SZ(a)-i-1]-'0';
		if(i<SZ(b)) c+=b[SZ(b)-i-1]-'0';
		while(i>=SZ(ret)) ret+="?";
		ret[i]='0'+c%10; c/=10;
	}
	reverse(ret.begin(),ret.end());
	//printf("'%s'+'%s'='%s'\n",a.c_str(),b.c_str(),ret.c_str());
	return ret;
}

string calc(int idx) {
	string a=s.substr(0,idx),b=s.substr(idx);
	return add(a,b);
}
string smaller(const string &a,const string &b) {
	if(SZ(a)!=SZ(b)) return SZ(a)<SZ(b)?a:b;
	return a<b?a:b;
}

void solve() {
	int best=INT_MAX; vector<int> bestopt; vector<int> best2opt; // best split has length at least best, possibly one more
	FOR(i,1,slen) if(s[i]!='0') {
		int a=i,b=slen-i;
		int cur=max(a,b);
		if(cur-1>best) continue;
		if(cur-1==best) { best2opt.PB(i); continue; }
		if(cur==best) { bestopt.PB(i); continue; }
		if(cur==best-1) { best2opt=bestopt; bestopt.clear(); best=cur; bestopt.PB(i); continue; }
		if(cur<best-1) { best2opt.clear(); bestopt.clear(); best=cur; bestopt.PB(i); continue; }
	}
	//printf("best=%d bestopt=",best); REPSZ(i,bestopt) { if(i!=0) printf(","); printf("%d",bestopt[i]); } printf(" bestopt2="); REPSZ(i,best2opt) { if(i!=0) printf(","); printf("%d",best2opt[i]); } puts("");

	ans=calc(bestopt[0]);
	FORSZ(i,1,bestopt) ans=smaller(ans,calc(bestopt[i]));
	REPSZ(i,best2opt) ans=smaller(ans,calc(best2opt[i]));
}

void run() {
	scanf("%d",&slen);
	cin>>s; assert(SZ(s)==slen);
	solve();
	printf("%s\n",ans.c_str());
}

int main() {
	run();
	return 0;
}