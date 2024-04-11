#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
 
llo n,q;
llo it[3][500001];
llo pre[3][500001];
llo dp[500001];
vector<pair<llo,llo>> pre5[500001];
vector<pair<llo,llo>> pre2[500001];
llo pre3[1001];
llo pre4[1001];
llo tree[4*500001];
llo tree3[4*500001];
 
void update(llo no,llo l,llo r,llo i,llo j){
	if(l==r){
		tree[no]=j;
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,j);
		}
		else{
			update(no*2+2,mid+1,r,i,j);
		}
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
 
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(aa>bb or r<aa or l>bb){
		return -(llo)1e18;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	llo mid=(l+r)/2;
	return max(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));
}
llo query3(llo no,llo l,llo r,llo aa,llo bb){
	if(aa>bb or r<aa or l>bb){
		return -(llo)1e18;
	}
	if(aa<=l and r<=bb){
		return tree3[no];
	}
	llo mid=(l+r)/2;
	return max(query3(no*2+1,l,mid,aa,bb),query3(no*2+2,mid+1,r,aa,bb));
}
llo tree2[4*500001][3];
void build2(llo no,llo l,llo r){
	if(l==r){
		tree3[no]=pre[0][l+1]-pre[1][l];
	}
	else{
		llo mid=(l+r)/2;
		build2(no*2+1,l,mid);
		build2(no*2+2,mid+1,r);
		tree3[no]=max(tree3[no*2+1],tree3[no*2+2]);
	}
}
void build(llo no,llo l,llo r,llo stt=0){
	if(l==r){
		tree2[no][0]=dp[l]-pre[1][l+1];
		if(stt==1){
			tree2[no][0]=pre[0][l+1]-pre[1][l];
		}
		tree2[no][1]=pre[1][l+1]+(pre[2][n]-pre[2][l]);
		tree2[no][2]=-(llo)1e18;
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid,stt);
		build(no*2+2,mid+1,r,stt);
		tree2[no][0]=max(tree2[no*2+1][0],tree2[no*2+2][0]);
		tree2[no][1]=max(tree2[no*2+1][1],tree2[no*2+2][1]);
		tree2[no][2]=max(tree2[no*2+1][2],tree2[no*2+2][2]);
		tree2[no][2]=max(tree2[no][2],tree2[no*2+1][0]+tree2[no*2+2][1]);
	}
}
vector<llo> qq;
void query2(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb or aa>bb){
		return ;
	}
	if(aa<=l and r<=bb){
		qq.pb(no);
	}
	else{
		llo mid=(l+r)/2;
		query2(no*2+1,l,mid,aa,bb);
		query2(no*2+2,mid+1,r,aa,bb);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(llo i=0;i<3;i++){
		for(llo j=0;j<n;j++){
			cin>>it[i][j];
			pre[i][j+1]=pre[i][j]+it[i][j];
		}
	}
	while(q--){
		llo l,r,k;
		cin>>l>>r>>k;
		l--;
		r--;
		pre5[l].pb({r,k});
		pre2[r].pb({l,k});
	}
	llo ans=-1e18;
	multiset<llo> cur;
	for(llo i=0;i<4*n;i++){
		tree[i]=-(llo)1e18;
	}
	build2(0,0,n-1);
	for(llo i=0;i<n;i++){
		for(auto j:pre5[i]){
			cur.insert(j.b);
		}
		dp[i]=(llo)1e18;
		dp[i]=-dp[i];
		if(cur.size()){
			llo j=*(cur.begin());
			dp[i]=max(dp[i],pre[0][i+1]+it[1][i]-(j));
			ans=max(ans,dp[i]+pre[2][n]-pre[2][i]);
		}
 
		for(auto j:pre2[i]){
			auto jj=cur.find(j.b);
			cur.erase(jj);
			
			llo ll=j.a;
			if(ll>0){
				ll--;
 
			}
 
			dp[i]=max(dp[i],query(0,0,n-1,ll,i-1)+pre[1][i+1]-j.b);
			dp[i]=max(dp[i],pre[1][i+1]-j.b+query3(0,0,n-1,j.a,i));
		}
		update(0,0,n-1,i,dp[i]-pre[1][i+1]);
		ans=max(ans,dp[i]+pre[2][n]-pre[2][i]);
	}
	//cout<<endl;
 
	build(0,0,n-1);
	
	for(llo i=0;i<n;i++){
		for(auto j:pre5[i]){
			llo l=i;
			llo r=j.a;
			if(l>0){
				l--;
			}
			qq.clear();
			query2(0,0,n-1,l,r);
			if(qq.size()==0){
				while(true){
					continue;
				}
			}
			for(auto ii:qq){
				ans=max(ans,tree2[ii][2]-j.b);
			}
 
			pre3[0]=-(llo)1e18;
			for(llo ii=1;ii<=qq.size();ii++){
				pre3[ii]=max(tree2[qq[ii-1]][0],pre3[ii-1]);
			}
 
			pre4[qq.size()]=-(llo)1e18;
			for(llo ii=(int)qq.size()-1;ii>=0;ii--){
				pre4[ii]=max(tree2[qq[ii]][1],pre4[ii+1]);
			}
			
			for(llo ii=1;ii<qq.size();ii++){
				ans=max(ans,-j.b+pre3[ii]+pre4[ii]);
			}
		}
	}
	build(0,0,n-1,1);
	for(llo i=0;i<n;i++){
		for(auto j:pre5[i]){
			llo l=i;
			llo r=j.a;
			qq.clear();
			query2(0,0,n-1,l,r);
			if(qq.size()==0){
				while(true){
					continue;
				}
			}
			for(auto ii:qq){
				ans=max(ans,tree2[ii][2]-j.b);
			}
 
			pre3[0]=-(llo)1e18;
			for(llo ii=1;ii<=qq.size();ii++){
				pre3[ii]=max(tree2[qq[ii-1]][0],pre3[ii-1]);
			}
 
			pre4[qq.size()]=-(llo)1e18;
			for(llo ii=(int)qq.size()-1;ii>=0;ii--){
				pre4[ii]=max(tree2[qq[ii]][1],pre4[ii+1]);
			}
			
			for(llo ii=1;ii<qq.size();ii++){
				ans=max(ans,-j.b+pre3[ii]+pre4[ii]);
			}
		}
	}
	cout<<ans<<endl;
 
 
 
 
 
	return 0;
}