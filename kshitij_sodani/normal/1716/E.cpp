#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

llo n;
llo it[1<<19];
llo tree[(1<<20)+10][4];
llo ll[(1<<20)+10];
llo rr[(1<<20)+10];
llo ans[(1<<20)+10];
void build(llo no,llo l,llo r){
	if(l==r){
 		llo x=it[l];
 		if(x<0){
 			x=0;
 		}
 		tree[no][0]=x;
 		tree[no][1]=x;
 		tree[no][2]=x;
 		tree[no][3]=it[l];
	}
	else{
		llo mid=(l+r)/2;
		ll[no]=no*2+1;
		rr[no]=no*2+2;
		build(ll[no],l,mid);
		build(rr[no],mid+1,r);
		tree[no][0]=max(tree[ll[no]][0],tree[ll[no]][3]+tree[rr[no]][0]);
		tree[no][1]=max(tree[rr[no]][1],tree[rr[no]][3]+tree[ll[no]][1]);
		tree[no][3]=tree[ll[no]][3]+tree[rr[no]][3];
		tree[no][2]=max(tree[ll[no]][2],tree[rr[no]][2]);
		tree[no][2]=max(tree[no][2],tree[ll[no]][1]+tree[rr[no]][0]);
	}
}
void solve(llo no,llo l,llo r,llo x){
	if(r-l+1==2*x){
 		swap(ll[no],rr[no]);
 		tree[no][0]=max(tree[ll[no]][0],tree[ll[no]][3]+tree[rr[no]][0]);
		tree[no][1]=max(tree[rr[no]][1],tree[rr[no]][3]+tree[ll[no]][1]);
		tree[no][3]=tree[ll[no]][3]+tree[rr[no]][3];
		tree[no][2]=max(tree[ll[no]][2],tree[rr[no]][2]);
		tree[no][2]=max(tree[no][2],tree[ll[no]][1]+tree[rr[no]][0]);
		return;
	}
	else{
		llo mid=(l+r)/2;
		solve(ll[no],l,mid,x);
		solve(rr[no],mid+1,r,x);
		tree[no][0]=max(tree[ll[no]][0],tree[ll[no]][3]+tree[rr[no]][0]);
		tree[no][1]=max(tree[rr[no]][1],tree[rr[no]][3]+tree[ll[no]][1]);
		tree[no][3]=tree[ll[no]][3]+tree[rr[no]][3];
		tree[no][2]=max(tree[ll[no]][2],tree[rr[no]][2]);
		tree[no][2]=max(tree[no][2],tree[ll[no]][1]+tree[rr[no]][0]);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<llo> ss;
	ss.pb(0);
	ss.pb(1<<(n-1));
	llo cur=n-1;
	for(llo i=0;i<n-1;i++){
		vector<llo> tt;
		for(auto j:ss){
			tt.pb(j);
		}
		cur--;
		reverse(ss.begin(),ss.end());
		for(auto j:ss){
			tt.pb(j+(1<<(cur)));
		}
		ss=tt;
	}
	for(llo i=0;i<(1<<n);i++){

		cin>>it[i];
	}
	/*for(auto j:ss){
		cout<<j<<",";
	}
	cout<<endl;
*/
	for(llo j=0;j<ss.size();j++){
		if(j==0){
			build(0,0,(1<<n)-1);
		}
		else{

			llo x=ss[j]^ss[j-1];
			//cout<<x<<","<<endl;
			//continue;
			solve(0,0,(1<<n)-1,x);
		}

		ans[ss[j]]=tree[0][2];
	}
		llo q;
		cin>>q;
		 cur=0;
		while(q--){
			llo x;
			cin>>x;
			cur^=(1<<x);
			cout<<ans[cur]<<endl;
		}

/*	*/









	return 0;
}