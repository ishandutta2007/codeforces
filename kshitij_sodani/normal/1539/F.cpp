#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;

int ans[200001];
int n;
int it[200001];
pair<int,int> tree[4*200002];

int lazy[4*200002];
void push(int no,int l,int r){
	tree[no].a+=lazy[no];
	tree[no].b+=lazy[no];
	if(l<r){
		lazy[no*2+1]+=lazy[no];
		lazy[no*2+2]+=lazy[no];
	}
	lazy[no]=0;
}
void update(int no,int l,int r,int aa,int bb,int val){
	push(no,l,r);
	if(r<aa or l>bb){
		return ;
	}
	if(aa<=l and r<=bb){
		lazy[no]=val;
		//cout<<aa<<":"<<bb<<endl;
		push(no,l,r);
	}
	else{
		int mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,val);
		update(no*2+2,mid+1,r,aa,bb,val);
		tree[no].a=max(tree[no*2+1].a,tree[no*2+2].a);
		tree[no].b=min(tree[no*2+1].b,tree[no*2+2].b);
	}
}
pair<int,int> query(int no,int l,int r,int aa,int bb){
	push(no,l,r);
	if(r<aa or l>bb){
		return {-n,n};
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	int mid=(l+r)/2;
	
	pair<int,int> xx=query(no*2+1,l,mid,aa,bb);
	pair<int,int> yy=query(no*2+2,mid+1,r,aa,bb);

	//tree[no].a=max(tree[no*2+1].a,tree[no*2+2].a);
	//tree[no].b=min(tree[no*2+1].b,tree[no*2+2].b);
	return {max(xx.a,yy.a),min(xx.b,yy.b)};
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	map<int,vector<int>> ss;
	map<int,vector<int>> tt;
	for(int i=0;i<n;i++){
		cin>>it[i];
		ss[it[i]].pb(i+1);
		tt[-it[i]].pb(i+1);
	}
	for(int i=0;i<=4*n;i++){
		tree[i]={0,0};
		lazy[i]=0;
	}
	for(int i=1;i<=n;i++){
		update(0,0,n,i,n,1);
	}
	for(auto j:ss){
		for(auto i:j.b){
			update(0,0,n,i,n,-1);

		/*	cout<<j.a<<":"<<i<<endl;
			for(int k=0;k<=n;k++){
				cout<<query(0,0,n,k,k).a<<",";
			}
			cout<<endl;*/
			ans[i]=max(ans[i],(query(0,0,n,i,n).a-query(0,0,n,0,i-1).b+1)/2);
			update(0,0,n,i,n,1);
		}
		for(auto i:j.b){
			update(0,0,n,i,n,-2);
		}
	}

	for(int i=0;i<=4*n;i++){
		tree[i]={0,0};
		lazy[i]=0;
	}
	for(int i=1;i<=n;i++){
		update(0,0,n,i,n,1);
	}

	for(auto j:tt){
		for(auto i:j.b){
			update(0,0,n,i,n,-1);
				/*cout<<j.a<<":"<<i<<endl;
			for(int k=0;k<=n;k++){
				cout<<query(0,0,n,k,k).a<<",";
			}
			cout<<endl;*/
			ans[i]=max(ans[i],(query(0,0,n,i,n).a-query(0,0,n,0,i-1).b)/2);
			update(0,0,n,i,n,1);
		}
		for(auto i:j.b){
			update(0,0,n,i,n,-2);
		}
	}

	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;












	return 0;
}