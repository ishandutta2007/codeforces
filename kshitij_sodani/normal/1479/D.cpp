//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n,q;
int it[300001];
mt19937 rng;
 
 
/*int cc=2329391;
int dd=3493942;*/
vector<int> adj[300001];
/*int mod=1e9+7;
int mod2=1e9+9;*/
 
int pre[300001];
int pre2[300001];
//
//vector<pair<int,int>> tree;
int ll[20000000];
int rr[20000000];
pair<int,int> tree[20000000];
//vector<int> rr;
int co[300001];
int cot=0;
int par2[300001][20];
int update(int no,int l,int r,int i,pair<int,int> j){
	if(l==r){
		tree[cot]=j;
		cot++;
		return cot-1;
	}
	else{
		int mid=(l+r)/2;
		int cur=cot;
 
		cot++;
		if(i<=mid){
			int x=update(ll[no],l,mid,i,j);
			ll[cur]=x;
			rr[cur]=rr[no];
		}
		else{
			int x=update(rr[no],mid+1,r,i,j);
			rr[cur]=x;
			ll[cur]=ll[no];
		}
		tree[cur].a=tree[ll[cur]].a^tree[rr[cur]].a;
		tree[cur].b=tree[ll[cur]].b^tree[rr[cur]].b;
		return cur;
	}
}
llo query(int no,int no2,int l,int r,int aa,int bb,int kk){
	if(l>bb or r<aa){
		return -1;
	}
	pair<int,int> ap={pre[it[kk]],pre2[it[kk]]};
		if(it[kk]<l or it[kk]>r){
			ap={0,0};
		}
	if((tree[no].a^tree[no2].a)==ap.a and (tree[no].b^tree[no2].b)==ap.b){
		return -1;
	}
	if(l==r){
		//cout<<l<<":"<<endl;
	//	cout<<tree[no].a<<":"<<tree[no2].a<<":"<<ap.a<<endl;
		return l;
	}
	else{
		int mid=(l+r)/2;
		llo	xx=query(ll[no],ll[no2],l,mid,aa,bb,kk);
		if(xx>-1){
			return xx;
		}
		llo yy=query(rr[no],rr[no2],mid+1,r,aa,bb,kk);
		return yy;
	}
}
int mm;
int build(int l,int r){
 
	int cur=cot;
	cot++;
	if(l!=r){
		int mid=(l+r)/2;
		ll[cur]=build(l,mid);
		rr[cur]=build(mid+1,r);
	}
	return cur;
}
int ver[300001];
 
int st[300001];
int endd[300001];
int pc=0;
int lev[300001];
pair<int,int> ppp[300001];
void dfs(int no,int par,int levv=0){
	par2[no][0]=par;
	lev[no]=levv;
	//cout<<no<<":"<<it[no]<<endl;
	st[no]=pc;
	pc++;
	if(co[it[no]]==1){
		ppp[no]={0,0};
		//cout<<no<<":"<<it[no]<<endl;
		mm=update(mm,0,n-1,it[no],{0,0});
 
	}
	else{
		ppp[no]={pre[it[no]],pre2[it[no]]};
 
		//cout<<no<<":"<<it[no]<<":"<<pre[it[no]]<<endl;
		//cout<<no<<":"<<endl;
		mm=update(mm,0,n-1,it[no],{pre[it[no]],pre2[it[no]]});
	}
	co[it[no]]^=1;
 
 
	ver[no]=mm;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no,levv+1);
		}
	}
	endd[no]=pc-1;
	if(co[it[no]]==1){
		mm=update(mm,0,n-1,it[no],{0,0});
		//cout<<no<<":"<<it[no]<<endl;
	}
	else{
 
		mm=update(mm,0,n-1,it[no],{pre[it[no]],pre2[it[no]]});
	}
	co[it[no]]^=1;
 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
	}
 
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());
 
	pre[0]=1;
	pre2[0]=1;
	for(int i=0;i<=n;i++){
		pre[i]=(rng()%(1LL<<30));
		pre2[i]=(rng()%(1LL<<30));
	}
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
 
	mm=build(0,n-1);
	//return 0;
	par2[n][0]=n;
	dfs(0,n);
	for(int j=1;j<19;j++){
		for(int i=0;i<=n;i++){
			par2[i][j]=par2[par2[i][j-1]][j-1];
		}
	}
 
	/*for(int i=0;i<n;i++){
		cout<<query(ver[i],0,n-1,1,1).a<<"::"<<endl;
	}
	for(int i=0;i<n;i++){
		cout<<query(ver[i],0,n-1,0,0).a<<"::"<<endl;
	}*/
	ver[n]=0;
	while(q--){
		int aa,bb,ee,ff;
		cin>>aa>>bb>>ee>>ff;
		aa--;
		bb--;
		ee--;
		ff--;
		if(st[aa]>st[bb]){
			swap(aa,bb);
		}
 
		//cout<<ee<<":"<<ff<<endl;
		if(aa==bb){
			if(it[aa]>=ee and it[aa]<=ff){
				cout<<it[aa]+1<<endl;
			}
			else{
				cout<<-1<<endl;
			}
			continue;
		}
 
/*
		for(int i=ee;i<=ff;i++){
			pair<int,int> xx;
			xx=query(ver[aa],0,n-1,i,i);
			pair<int,int> yy;
			yy=query(ver[bb],0,n-1,i,i);
			cout<<xx.a<<",,"<<yy.a<<endl;
		}*/
		int xx,yy;
		if(st[aa]<=st[bb] and endd[bb]<=endd[aa]){
			xx=aa;
			
		}
		else{
			int ma1=aa;
			int ma2=bb;
			if(lev[aa]>lev[bb]){
				swap(ma1,ma2);
			}
			int dif=lev[ma2]-lev[ma1];
			for(int j=18;j>=0;j--){
				if((1<<j)&dif){
					ma2=par2[ma2][j];
				}
			}
			for(int j=18;j>=0;j--){
				if(par2[ma1][j]!=par2[ma2][j]){
					ma1=par2[ma1][j];
					ma2=par2[ma2][j];
				}
			}
			xx=par2[ma1][0];
 
		}
		yy=par2[xx][0];
		
		llo ans=query(ver[aa],ver[bb],0,n-1,ee,ff,xx);
		
		if(ans==-1){
			cout<<-1<<endl;
		}
		else{
			cout<<ans+1<<endl;
		}
		continue;
		
		
 
	}
	/*for(int i=0;i<n;i++){
		cout<<ver[i]<<",";
	}
	cout<<endl;*/
 
 
 
 
 
 
 
 
 
	return 0;
}