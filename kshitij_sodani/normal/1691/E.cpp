#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo aa[200001];
llo bb[200001];
llo it[200001];
vector<pair<llo,llo>> tree[8*100001][2];
llo vis[200001];
llo ii;
llo n;
void update(llo no,llo l,llo r,llo i,llo j,llo kk){
	tree[no][kk].pb({j,ii});
	if(l<r){
		llo mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,j,kk);
		}
		else{
			update(no*2+2,mid+1,r,i,j,kk);
		}
	}
}

vector<llo> tt;
void query(llo no,llo l,llo r,llo aa,llo bb,llo x,llo kk){
	if(r<aa or l>bb or aa>bb){
		return;
	}
	if(aa<=l and r<=bb){
		while(tree[no][kk].size()){
			if(tree[no][kk].back().a>=x){
				tt.pb(tree[no][kk].back().b);
				tree[no][kk].pop_back();
			}
			else{
				break;
			}
		}
	}
	else{
		llo mid=(l+r)/2;
		query(no*2+1,l,mid,aa,bb,x,kk);
		query(no*2+2,mid+1,r,aa,bb,x,kk);
	}
}
void dfs(llo no){
	vis[no]=1;
	tt.clear();
	query(0,0,2*n-1,0,aa[no]-1,aa[no],1-it[no]);
	query(0,0,2*n-1,aa[no],bb[no],0,1-it[no]);
	vector<llo> ee=tt;
	for(auto j:ee){
		if(vis[j]==0){
			dfs(j);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		
		cin>>n;
		for(llo i=0;i<8*n;i++){
			tree[i][0].clear();
			tree[i][1].clear();
		}
		map<llo,llo> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i]>>aa[i]>>bb[i];
			ss[aa[i]]++;
			ss[bb[i]]++;
		}
		llo ind=0;
		map<llo,llo> tt;
		for(auto j:ss){
			tt[j.a]=ind;
			ind++;
		}
		for(llo i=0;i<n;i++){
			aa[i]=tt[aa[i]];
			bb[i]=tt[bb[i]];
			ii=i;
			update(0,0,2*n-1,aa[i],bb[i],it[i]);
		}
		for(llo i=0;i<8*n;i++){
			if(tree[i][1].size()){
				sort(tree[i][1].begin(),tree[i][1].end());
			}
			if(tree[i][0].size()){
				sort(tree[i][0].begin(),tree[i][0].end());
			}
		}
		for(llo i=0;i<n;i++){
			vis[i]=0;
		}
		llo ans=0;
		for(llo i=0;i<n;i++){
			if(vis[i]==0){
				dfs(i);
				ans++;
			}
		}
		cout<<ans<<endl;

	}







	return 0;
}