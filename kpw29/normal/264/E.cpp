//PRZEMYSL ASSERTY
//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE
//MODULO = 1
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define foreach(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define scanf(...) scanf(__VA_ARGS__)?:0
#define e1 first
#define e2 second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii tp[500001];
int n,m,t[500001],p[500001],h[500001],w[500001],ms[500001],tx[1<<20],ty[1<<20],sx[1<<20],sy[1<<20];
vector<int> v;
void ustaw(int *t,int *tz,int a,int x,int f) {
	a+=1<<19;
	t[a]=x;
	tz[a]=f;
	a>>=1;
	while (a) {
		t[a]=max(t[a+a],t[a+a+1]);
		tz[a]=tz[a+a]+tz[a+a+1];
		a>>=1;
	}
}
int maks(int *t,int a,int b) {
	a+=(1<<19)-1; b+=(1<<19)+1; int ret=0;
	while (a+1<b) {
		if (a%2==0 && ret<t[a+1]) ret=t[a+1];
		if (b%2==1 && ret<t[b-1]) ret=t[b-1];
		a>>=1; b>>=1;
	}
	return ret;
}
int suma(int *t,int a,int b) {
	a+=(1<<19)-1; b+=(1<<19)+1; int ret=0;
	while (a+1<b) {
		if (a%2==0) ret+=t[a+1];
		if (b%2==1) ret+=t[b-1];
		a>>=1; b>>=1;
	}
	return ret;
}
int find_min(int *t,int ktory) {
	if (t[1]<ktory) return -1;
	int nr=1;
	while (nr<(1<<19)) {
		nr<<=1;
		if (t[nr]<ktory) ktory-=t[nr++];
	}
	return nr-(1<<19);
}
int main() {
	scanf("%d%d",&n,&m);
	FOR(i,1,m) {
		scanf("%d",&t[i]);
		if (t[i]==1) scanf("%d%d",&p[i],&h[i]),tp[p[i]]=mp(h[i]-i,p[i]);
		else scanf("%d",&p[i]);
	}
	sort(tp+1,tp+n+1);
	FOR(i,1,n) w[tp[i].e2]=i;
	FOR(i,1,m) if (t[i]==1) {
		h[i]=w[p[i]];
		ms[h[i]]=p[i];
	}
	FOR(i,1,m) {
		if (t[i]==1) {
			while (true) {
				int y=find_min(sy,v.size()+1);
				if (y==-1 || h[i]<y) break;
				v.push_back(y);
			}
			foreach(it,v) ustaw(tx,sx,ms[*it],0,0);
			int wn=maks(tx,p[i]+1,n)+1;
			ustaw(tx,sx,p[i],wn,1);
			ustaw(ty,sy,h[i],wn,1);
			reverse(all(v));
			foreach(it,v) {
				wn=maks(tx,ms[*it]+1,n)+1;
				ustaw(tx,sx,ms[*it],wn,1);
				ustaw(ty,sy,*it,wn,1);
			}
		} else {
			REP(j,p[i]) {
				int x=find_min(sx,v.size()+1);
				v.push_back(x);
			}
			foreach(it,v) ustaw(ty,sy,w[*it],0,0);
			ustaw(tx,sx,v.back(),0,0);
			v.pop_back();
			reverse(all(v));
			foreach(it,v) {
				int wn=maks(ty,w[*it]+1,n)+1;
				ustaw(tx,sx,*it,wn,1);
				ustaw(ty,sy,w[*it],wn,1);
			}
		}
		int ans=maks(tx,1,n);
		printf("%d\n",ans);
		v.clear();
	}
}