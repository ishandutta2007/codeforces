#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

struct WT {
	vector<int> wt[1<<22];int n;
	void init(int k, int s, int e){
		if(s+1==e)return;
		wt[k].clear();wt[k].pb(0);
		int m=(s+e)/2;
		init(2*k,s,m);init(2*k+1,m,e);
	}
	void add(int k, int s, int e, int v){
		if(s+1==e)return;
		int m=(s+e)/2;
		if(v<m)wt[k].pb(wt[k].back()),add(2*k,s,m,v);
		else wt[k].pb(wt[k].back()+1),add(2*k+1,m,e,v);
	}
	int query(int k, int s, int e, int a, int b, int a0, int b0){
		if(s>=b0||e<=a0)return 0;
		if(s>=a0&&e<=b0)return b-a;
		int m=(s+e)/2;
		return query(2*k,s,m,a-wt[k][a],b-wt[k][b],a0,b0)+query(2*k+1,m,e,wt[k][a],wt[k][b],a0,b0);
	}
	void init(int _n){n=_n;init(1,0,n);}
	void add(int v){add(1,0,n,v);}
	int query(int a, int b, int a0, int b0){return query(1,0,n,a,b,a0,b0);}
};

WT w;
int n,m;
pair<int,int> x[1<<20];

int main(){
	w.init(1000005);
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		int l,r;
		scanf("%d%d",&l,&r);r++;
		x[i]=mp(l,r);
	}
	sort(x,x+n);
	fore(i,0,n)w.add(x[i].snd);
	while(m--){
		int q;
		scanf("%d",&q);
		vector<int> v;v.pb(0);
		while(q--){
			int a;
			scanf("%d",&a);
			v.pb(a);
		}
		int r=0;
		fore(i,1,v.size()){
			int a=lower_bound(x,x+n,mp(v[i-1]+1,-1))-x;
			int b=lower_bound(x,x+n,mp(v[i]+1,-1))-x;
			r+=w.query(a,b,v[i]+1,1000002);
		}
		printf("%d\n",r);
	}
	return 0;
}