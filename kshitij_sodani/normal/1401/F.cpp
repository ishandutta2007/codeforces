//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,q;
llo nn=n;
llo it[300001];
llo cc[30];
llo dd[30];
llo vis[30];
llo vis2[30];
llo tree[4*300001];
llo cot[4*300001];
//llo lazy[4*300001];

llo le[4*300001];
llo re[4*300001];
llo co[300001];
void build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=it[l];
	}
	else{
		llo mid=(l+r)/2;
		le[no]=no*2+1;
		re[no]=no*2+2;
		build(le[no],l,mid);
		build(re[no],mid+1,r);
		tree[no]=tree[le[no]]+tree[re[no]];
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(l<r){
		/*if(vis[co[r-l+1]]){
			if(dd[co[r-l+1]].find(no)==dd[co[r-l+1]].end()){
				dd[co[r-l+1]].insert(no);
				lazy[no]^=1;
			}
			
		}
		if(lazy[no]){
				swap(le[no],re[no]);
				lazy[le[no]]^=1;
				lazy[re[no]]^=1;
				lazy[no]=0;
			}*/
			if(cot[no]<cc[co[r-l+1]]){
				
			llo xx=(cc[co[r-l+1]]-cot[no])%2;
			if(xx%2==1){
				swap(le[no],re[no]);
			}
			cot[no]=cc[co[r-l+1]];
		}
		/*if(vis2[co[r-l+1]]){
			if(cot[co[r-l+1]].find(no)==cc[co[r-l+1]].end()){
				cc[co[r-l+1]].insert(no);
				swap(le[no],re[no]);
			}
		}*/
	}
	if(bb<l or aa>r){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	else{
		llo mid=(l+r)/2;


		llo xx=query(le[no],l,mid,aa,bb)+query(re[no],mid+1,r,aa,bb);
		tree[no]=tree[le[no]]+tree[re[no]];
		return xx;

	}
}
void update(llo no,llo l,llo r,llo i,llo j){
	if(l==r){
		tree[no]=j;
		return;
	}
	if(l<r){
		/*if(vis[co[r-l+1]]){
			if(dd[co[r-l+1]].find(no)==dd[co[r-l+1]].end()){
				dd[co[r-l+1]].insert(no);
				lazy[no]^=1;
			}
			
		}
		if(lazy[no]){
				swap(le[no],re[no]);
				lazy[le[no]]^=1;
				lazy[re[no]]^=1;
				lazy[no]=0;
			}*/
		if(cot[no]<cc[co[r-l+1]]){

			llo xx=(cc[co[r-l+1]]-cot[no])%2;
			if(xx%2==1){
				swap(le[no],re[no]);
			}
			cot[no]=cc[co[r-l+1]];
		}
		/*if(vis2[co[r-l+1]]){
			if(cc[co[r-l+1]].find(no)==cc[co[r-l+1]].end()){
				cc[co[r-l+1]].insert(no);
				swap(le[no],re[no]);
			}
		}*/
	}


		llo mid=(l+r)/2;

		if(i<=mid){
			update(le[no],l,mid,i,j);
		}
		else{
			update(re[no],mid+1,r,i,j);
		}
		tree[no]=tree[le[no]]+tree[re[no]];


	






}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	nn=(1<<n);
	for(llo i=0;i<nn;i++){
		cin>>it[i];
	}
	for(llo i=0;i<=n;i++){
		co[(1<<i)]=i;
	}
	build(0,0,nn-1);
	while(q--){
		llo t;
		cin>>t;
		
		if(t==4){
			llo l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<query(0,0,nn-1,l,r)<<endl;
		}
		else if(t==2){
			llo k;
			cin>>k;
			vis[k]=1;
			for(llo i=0;i<=k;i++){
				cc[i]+=1;
			}
		//	dd[k].clear();
		}
		else if(t==3){
			llo k;
			cin>>k;
			cc[k+1]+=1;
		}
		else{
			llo i,j;
			cin>>i>>j;
			i--;
			update(0,0,nn-1,i,j);
		}
	//	cout<<query(0,0,nn-1,1,3)<<":"<<endl;

	}




 
 
	return 0;
}