#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define a first
#define b second
#define pb push_back
int tree[1200001];
int lazy[1200001];
void update(int no,int l,int r,int aa,int bb,int val){
	if(lazy[no]!=0){
		tree[no]+=lazy[no];
		if(l<r){
			lazy[no*2+1]+=lazy[no];
			lazy[no*2+2]+=lazy[no];
		}
		lazy[no]=0;
	}
	if(r<aa or l>bb or l>r){
		return;
	}
	else if(aa<=l and r<=bb){
		tree[no]+=val;
		if(l<r){
			lazy[no*2+1]+=val;
			lazy[no*2+2]+=val;
		}
	}
	else{
		int mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,val);
		update(no*2+2,mid+1,r,aa,bb,val);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
int query(int no,int l,int r,int aa,int bb){
	if(lazy[no]!=0){
		tree[no]+=lazy[no];
		if(l<r){
			lazy[no*2+1]+=lazy[no];
			lazy[no*2+2]+=lazy[no];
		}
		lazy[no]=0;
	}
	if(l>bb or r<aa or l>r){
		return -10;
	}
	else if(l>=aa and r<=bb){
		return tree[no];
	}
	else{
		int mid=(l+r)/2;
		query(no*2+1,l,mid,aa,bb);
		query(no*2+2,mid+1,r,aa,bb);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
		return tree[no];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int aa[n];
	int bb[n];
	int ind[n];
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
	for(int i=0;i<n;i++){
		cin>>aa[i];
		aa[i]-=1;
		ind[aa[i]]=i;
	}
	for(int i=0;i<n;i++){
		cin>>bb[i];
		bb[i]-=1;
	}
	int ans=n-1;
	//set<int> indd;

	for(int i=0;i<n;i++){
		if(i==0){
			cout<<n<<" ";;
			update(0,0,n-1,0,ind[n-1],1);
	//		cout<<0<<" "<<ind[n-1]<<" "<<"+1"<<endl;
			continue;
		}
		if(i>0){
			update(0,0,n-1,0,bb[i-1],-1);
	//		cout<<0<<" "<<bb[i-1]<<"-"<<-1<<endl;
		}
		while(true){
			int x=query(0,0,n-1,0,n-1);
	//		cout<<x<<":"<<ans<<endl;
			if(x<=0){
				ans-=1;
				update(0,0,n-1,0,ind[ans],1);
	//			cout<<0<<" "<<ind[ans]<<"+1"<<endl;
				continue;
			}
			break;
		}
		cout<<ans+1<<" ";
	}
	cout<<endl;

	return 0;
}