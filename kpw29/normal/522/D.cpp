#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000111;
const int SS=1<<20;
int tree[2*SS+69];
const int INF=(int)1e9+696969;
void ustaw(){
	for(int i=1;i<=2*SS+60;i++) tree[i]=INF;
}
void dodaj(int a,int b,int val){
	a++,b++;
	a+=SS,b+=SS;
	tree[a]=min(val,tree[a]),tree[b]=min(val,tree[b]);
	while(a+1<b){
		if(a%2==0) tree[a+1]=min(val,tree[a+1]);
		if(b%2==1) tree[b-1]=min(val,tree[b-1]);
		a/=2,b/=2;
	}
}
int query(int pos){
	pos++;
	pos+=SS;
	int wyn=tree[pos];
	while(pos>0){
		wyn=min(wyn,tree[pos]);
		pos/=2;
	}
	return wyn;
}
map<int,int> ost;
typedef pair<int,int> PII;
vector<PII> pytania[MAXN];
int wyn[MAXN];
int tab[MAXN];
main(){
	ustaw();
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&tab[i]);
	for(int j=1;j<=m;j++){
		int l,r;scanf("%d%d",&l,&r);
		pytania[r].emplace_back(l,j);
	}
	for(int i=1;i<=n;i++){
		int k=tab[i];
		if(ost.find(k)==ost.end()){
			ost[k]=i;
		}
		else {
			int pop=ost[k];
			dodaj(0,pop,i-pop);
			ost[k]=i;
		}
		for(auto it:pytania[i]){
			int lw,nr;tie(lw,nr)=it;
			wyn[nr]=query(lw);
			if(wyn[nr]==INF) wyn[nr]=-1;
		}
	}
	for(int i=1;i<=m;i++) printf("%d\n",wyn[i]);
	return 0;
}