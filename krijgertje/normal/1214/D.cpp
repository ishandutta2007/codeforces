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

const int DX[]={-1,0,+1,0};
const int DY[]={0,+1,0,-1};

int h,w;
vector<string> g;

vector<vector<int>> been;
vector<vector<int>> used;

bool go(int cx,int cy,int tx,int ty,int k1,int k2,int mask) {
	if(been[cx][cy]&mask) return false; else been[cx][cy]^=mask;
	used[cx][cy]^=mask;
	if(cx==tx&&cy==ty) return true;
	REP(rep,2) {
		int k=rep==0?k1:k2;
		int nx=cx+DX[k],ny=cy+DY[k];
		if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='#') continue;
		if(go(nx,ny,tx,ty,k1,k2,mask)) return true;
	}
	used[cx][cy]^=mask;
	return false;
}

int solve() {
	been=used=vector<vector<int>>(h,vector<int>(w,0));
	if(!go(0,0,h-1,w-1,1,2,1)) return 0;
	if(!go(0,0,h-1,w-1,2,1,2)) return 0;
	REP(x,h) REP(y,w) if((x!=0||y!=0)&&(x!=h-1||y!=w-1)&&used[x][y]==3) return 1;
	return 2;
}

void run() {
	scanf("%d%d",&h,&w);
	g=vector<string>(h); REP(x,h) { string s; cin>>s; g[x]=s; }
	printf("%d\n",solve());

}

int main() {
	run();
	return 0;
}