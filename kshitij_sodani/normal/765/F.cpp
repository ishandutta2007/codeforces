#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

llo n;
llo it[300001];
llo aa[300001];
llo pre[300001];
llo ans[300001];
vector<pair<llo,llo>> pre2[300001];
vector<pair<llo,llo>> pre3[300001];

llo le[100001][21];
llo re[100001][21];
llo ll[300001];

llo rr[300001];


llo tree[4*100001];
llo tree2[4*100001];
void update2(llo no,llo l,llo r,llo i,llo j){
	if(l==r){
		tree2[no]=min(tree2[no],j);
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update2(no*2+1,l,mid,i,j);
		}
		else{
			update2(no*2+2,mid+1,r,i,j);
		}
		tree2[no]=min(tree2[no*2+1],tree2[no*2+2]);
	}
}
llo query2(llo no,llo l,llo r,llo aa,llo bb,llo x){
	if(r<aa or l>bb or aa>bb){
		return -1;
	}
	if(tree2[no]>x){
		return -1;
	}
	if(aa<=l and r<=bb){
		if(l==r){
			if(tree2[no]<=x){
				return l;
			}
			else{
				return -1;
			}
		}
		llo mid=(l+r)/2;
		if(tree2[no*2+1]<=x){
			return query2(no*2+1,l,mid,aa,bb,x);
		}
		return query2(no*2+2,mid+1,r,aa,bb,x);
	}

	llo mid=(l+r)/2;
	llo pp=query2(no*2+1,l,mid,aa,bb,x);
	if(pp>=0){
		return pp;
	}
	return query2(no*2+2,mid+1,r,aa,bb,x);
}
void update(llo no,llo l,llo r,llo i,llo j){
	if(l==r){
		tree[no]=min(tree[no],j);
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,j);
		}
		else{
			update(no*2+2,mid+1,r,i,j);
		}
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb or aa>bb){
		return 1e9+1;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	llo mid=(l+r)/2;
	return min(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));
}

llo q;
void solve(){
	for(llo i=0;i<n-1;i++){
		aa[i]=it[i+1]-it[i];
		pre[i+1]=pre[i]+aa[i];
	}
	vector<pair<llo,llo>> ss;
	for(llo i=n-1;i>=0;i--){
		while(ss.size()){
			if(ss.back().a<pre[i]){
				ss.pop_back();
			}
			else{
				break;
			}
		}
		
		if(ss.size()){
			re[i][0]=ss.back().b;
		}
		else{
			re[i][0]=-1;
		}
		ss.pb({pre[i],i});
	}
	ss.clear();


	ss.clear();
	for(llo j=1;j<20;j++){
		for(llo i=0;i<n;i++){
			if(re[i][j-1]==-1){
				re[i][j]=-1;
			}
			else{
				re[i][j]=re[re[i][j-1]][j-1];
			}
		}
	}

	vector<pair<llo,llo>> ee;
	for(llo i=0;i<n;i++){
		ee.pb({pre[i],i});
	}
	sort(ee.begin(),ee.end());
	reverse(ee.begin(),ee.end());
	for(llo i=0;i<4*n;i++){	
		tree2[i]=(llo)1e18;
	}
	for(auto ii:ee){
		llo i=ii.b;
		if(re[i][0]>=0){
			llo cur=re[i][0];
			while(true){
			
				if(cur==-1){
					break;
				}
				if(pre[cur]<pre[i]){
					break;
				}
				pre2[i].pb({cur,abs(pre[cur]-pre[i])});
				if(pre[i]==pre[cur]){
					break;
				}
				cur=query2(0,0,n-1,cur+1,n-1,(pre[i]+pre[cur])/2);
			}
		}
		update2(0,0,n-1,i,pre[i]);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<4*n;i++){
		tree[i]=1e9+1;
	}
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	
	cin>>q;
	for(llo ii=0;ii<q;ii++){
		cin>>ll[ii]>>rr[ii];
		ll[ii]--;
		rr[ii]--;
		ans[ii]=1e9+1;
		pre3[ll[ii]].pb({rr[ii],ii});
	}

	
	solve();
	for(int i=0;i<n;i++){
		it[i]=1e9-it[i];
	}
	solve();

	for(llo i=n-1;i>=0;i--){
		for(auto j:pre2[i]){
			update(0,0,n-1,j.a,j.b);
		}
		for(auto j:pre3[i]){
			ans[j.b]=min(ans[j.b],query(0,0,n-1,i,j.a));
		}
	}





	for(llo i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}


	return 0;
}