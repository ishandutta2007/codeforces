#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const char F0[]="What are you doing at the end of the world? Are you busy? Will you save us?";
const char G0[]="What are you doing while sending \"";
const char G1[]="\"? Are you busy? Will you send \"";
const char G2[]="\"?";

int f0len;
int g0len,g1len,g2len;

vector<ll> len;
char solve(int n,ll idx) {
	if(n==0) return idx<f0len?F0[idx]:'.';
	if(idx<g0len) return G0[idx]; else idx-=g0len;
	if(n-1>=SZ(len)||idx<len[n-1]) return solve(n-1,idx); else idx-=len[n-1];
	if(idx<g1len) return G1[idx]; else idx-=g1len;
	if(n-1>=SZ(len)||idx<len[n-1]) return solve(n-1,idx); else idx-=len[n-1];
	if(idx<g2len) return G2[idx]; else idx-=g2len;
	return '.';
}

int n; ll idx;
void run() {
	scanf("%d%lld",&n,&idx); --idx;

	len.clear(); len.PB(f0len); while(idx>=len.back()) len.PB(2*len.back()+g0len+g1len+g2len);
	printf("%c",solve(n,idx));
}

int main() {
	f0len=strlen(F0); g0len=strlen(G0); g1len=strlen(G1); g2len=strlen(G2);
	int n; scanf("%d",&n); FORE(i,1,n) run(); puts("");
	return 0;
}