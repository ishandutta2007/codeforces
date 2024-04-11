#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define FORD(i,s,e) for(int i=s;i>=e;i--)
#define ALL(k) (k).begin(),(k).end()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int MAXN=500111;
int fu[MAXN];

int find(int v){
	if(fu[v]<0) return v;
	fu[v]=find(fu[v]);
	return fu[v];
}
int unia(int a,int b){
	int aa=find(a),bb=find(b);
	if(aa==bb) return 0;
	//printf("unia %d %d %d;; %d %d %d:: ",a,aa,fu[aa],b,bb,fu[bb]);
	if(fu[aa]>fu[bb]) swap(aa,bb);
	fu[aa]+=fu[bb];
	fu[bb]=aa;
	//printf("%d %d\n",fu[aa],fu[bb]);
	return 1;
}
const int SS=1<<20;
int tree[2*SS+69];
vector<int> tr2[2*SS+69];
void phaj(int v){
	if(tree[v]==0) return;
	//printf("phaj %d %d\n",v,(int)tr2[v].size());
	for(auto it:tr2[v]){
		unia(tree[v],it);
	}
	tr2[v].clear();
	if(tree[2*v]!=0) unia(tree[v],tree[2*v]);
	if(tree[2*v+1]!=0) unia(tree[v],tree[2*v+1]);
	tree[2*v]=tree[2*v+1]=tree[v];
	//tree[v]=0;
}
int st,en,val;
void insert(int a,int b,int v){
	//printf("ins %d %d %d %d::\n",a,b,v,tree[v]);
	if(st<=a&&b<=en) {
		if(tree[v]!=0)unia(tree[v],val);
		//printf("OK %d %d\n",tree[v],val);
		tree[v]=val;
		for(auto it:tr2[v]) unia(tree[v],it);
		return;
	}
	phaj(v);
	int sr=(a+b)/2;
	if(st<=sr) insert(a,sr,2*v);
	if(sr<en) insert(sr+1,b,2*v+1);
	tr2[v].push_back(val);
}
int query(int a,int b,int v){
	//printf("que %d %d %d %d::\n",a,b,v,tree[v]);
	if(a==b&&a==st) return find(a);
	phaj(v);
	int sr=(a+b)/2;
	if(st<=sr) return query(a,sr,2*v);
	return query(sr+1,b,2*v+1);
}

void ins2(int v,int val){
	while(v>0){
		//printf("wrzuc %d\n",v);
		tr2[v].push_back(val);
		if(tree[v]!=0) unia(tree[v],val);
		v/=2;
	}
}
		





main(){
	int n,q;scanf("%d%d",&n,&q);
	FOR(i,1,n) fu[i]=-1;
	FOR(i,1,n) tree[i+SS-1]=i;
	FOR(i,1,q){
		int typ;scanf("%d",&typ);
		int x,y;scanf("%d%d",&x,&y);
		if(typ==1) {
			unia(x,y);
			ins2(x+SS-1,find(y));
			ins2(y+SS-1,find(y));
			continue;
		}
		if(typ==2){
			st=x,en=y;
			unia(x,y);
			val=find(x);
			insert(1,SS,1);
			continue;
		}
		st=en=x;
		int a1=query(1,SS,1);
		st=en=y;
		int a2=query(1,SS,1);
		a1=find(x),a2=find(y);
		//printf("%d %d",a1,a2);
		puts(a1==a2?"YES":"NO");
	}
	return 0;
}