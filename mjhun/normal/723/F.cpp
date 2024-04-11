#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define ws demetrio
using namespace std;

typedef long long ll;

int uf[200005];
vector<pair<int,int> > sol;

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

void join(int xx, int yy){
	int x=find(xx),y=find(yy);
	if(x==y)return;
	sol.pb(mp(xx,yy));
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
}

int n,m;
pair<int,int> e[400005];
int s,t,ds,dt;
int ws[200005];
int wt[200005];
vector<int> ss,tt,bb;

int main(){
	scanf("%d%d",&n,&m);
	memset(uf,-1,sizeof(uf));
	fore(i,0,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[i]=mp(x-1,y-1);
	}
	scanf("%d%d%d%d",&s,&t,&ds,&dt);s--;t--;
	fore(i,0,m){
		if(e[i].fst!=s&&e[i].snd!=s&&e[i].fst!=t&&e[i].snd!=t)join(e[i].fst,e[i].snd);
	}
	memset(ws,-1,sizeof(ws));memset(wt,-1,sizeof(wt));
	fore(i,0,m){
		if(e[i].fst==s||e[i].snd==s)ws[find(e[i].fst+e[i].snd-s)]=e[i].fst+e[i].snd-s;
		if(e[i].fst==t||e[i].snd==t)wt[find(e[i].fst+e[i].snd-t)]=e[i].fst+e[i].snd-t;
	}
	fore(i,0,n){
		if(i==s||i==t||uf[i]>=0)continue;
		if(ws[i]>=0&&wt[i]>=0)bb.pb(i);
		else if(ws[i]>=0)ss.pb(i);
		else if(wt[i]>=0)tt.pb(i);
	}
	if(ds<=ss.size()||dt<=tt.size()){puts("No");return 0;}
	ds-=ss.size();dt-=tt.size();
	fore(i,0,ss.size())sol.pb(mp(s,ws[ss[i]]));
	fore(i,0,tt.size())sol.pb(mp(t,wt[tt[i]]));
	if(ds+dt<=bb.size()){puts("No");return 0;}
	fore(i,0,bb.size()){
		if(ds>0){
			sol.pb(mp(s,ws[bb[i]]));
			ds--;
		}
		else {
			assert(dt>1);
			sol.pb(mp(t,wt[bb[i]]));
			dt--;
		}
	}
	if(!bb.size())sol.pb(mp(s,t));
	else sol.pb(mp(t,wt[bb[0]]));
	puts("Yes");assert(sol.size()==n-1);
	fore(i,0,sol.size()){
		printf("%d %d\n",sol[i].fst+1,sol[i].snd+1);
	}
	return 0;
}