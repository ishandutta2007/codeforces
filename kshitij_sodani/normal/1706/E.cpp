#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo aa[200001];
llo par[200001];
llo l[200001];
llo r[200001];
llo bb[200001];
llo low[200001];
 
llo high[200001];
 
llo mid[200001];
vector<pair<llo,llo>> pre[200001];
llo ans[200001];
llo find(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
llo tree[4*200001];
void build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=ans[l];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb or aa>bb){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	llo mid=(l+r)/2;
	return max(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m,q;
		cin>>n>>m>>q;
		for(llo i=0;i<m;i++){
			cin>>aa[i]>>bb[i];
			aa[i]--;
			bb[i]--;
		}
		for(llo i=0;i<n-1;i++){
			low[i]=0;
			high[i]=m;
		}
		for(llo i=0;i<q;i++){
			cin>>l[i]>>r[i];
			l[i]--;
			r[i]--;
		}
		for(llo jj=0;jj<20;jj++){
			for(llo i=0;i<n;i++){
				par[i]=i;
			}
			for(llo i=0;i<=m;i++){
				pre[i].clear();
			}
			for(llo i=0;i<n-1;i++){
 
				mid[i]=(low[i]+high[i])/2;
				pre[mid[i]].pb({i,i+1});
			
			}
			for(llo i=0;i<=m;i++){
				for(auto j:pre[i]){
 
					if(find(j.a)==find(j.b)){
						high[j.a]=mid[j.a];
						if(jj==19){
							ans[j.a]=mid[j.a];
						}
					}
					else{
						low[j.a]=mid[j.a];
						if(jj==19){
 
							ans[j.a]=mid[j.a]+1;
						}
					}
				}
				if(i==m){
					break;
				}
				llo x=find(aa[i]);
				llo y=find(bb[i]);
				if(x!=y){
					par[x]=y;
				}
			}
		}
		
		build(0,0,n-2);
		for(llo i=0;i<q;i++){
			cout<<query(0,0,n-2,l[i],r[i]-1)<<" ";
		}
		cout<<endl;
	}
 
 
 
 
 
 
	return 0;
}