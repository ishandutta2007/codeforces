#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

#define MAXN 100005

int ft[MAXN+1];
void upd(int i0, int v){for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;}
int get(int i0){
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get(int i0, int i1){return get(i1)-get(i0);}

int n,m;
int a[100005],r[100005];
vector<pair<int,int> > q[100005];
map<int,vector<int> > w;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,m){
		int s,e;
		scanf("%d%d",&s,&e);s--;
		q[e-1].pb(mp(s,i));
	}
	fore(i,0,n){
		vector<int>& v=w[a[i]];
		v.pb(i);
		if(SZ(v)>=a[i])upd(v[SZ(v)-a[i]],1);
		if(SZ(v)>a[i])upd(v[SZ(v)-a[i]-1],-2);
		if(SZ(v)-1>a[i])upd(v[SZ(v)-a[i]-2],1);
		for(auto p:q[i])r[p.snd]=get(p.fst,n);
	}
	fore(i,0,m)printf("%d\n",r[i]);
	return 0;
}