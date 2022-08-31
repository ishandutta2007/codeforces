#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
int n,m,k,r,c,ax,ay,bx,by;
ll rect(int x1,int y1,int x2,int y2) {
	if(x1<=x2&&y1<=y2) return (x2-x1+1)*ll(y2-y1+1);
	return 0;
}
const int MOD=1e9+7;
ll qp(ll a,ll b) {
	ll x=1; a%=MOD;
	while(b) {
		if(b&1) x=x*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return x;
}
int main()
{
	cin>>n>>m>>k>>r>>c>>ax>>ay>>bx>>by;
	ll cel=n*(ll)m;
	int dx=abs(ax-bx),dy=abs(ay-by);
	if(ax==bx&&ay==by) {
		;
	}
	else {
		cel-=r*(ll)c*2;
		cel+=rect(max(ax,bx),max(ay,by),min(ax+r-1,bx+r-1),
		min(ay+c-1,by+c-1));
		cel+=r*(ll)c;
		cel-=max(r-dx,0)*ll(max(c-dy,0));
	}
	cout<<qp(k,cel)%MOD<<"\n";
}