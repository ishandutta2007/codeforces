//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo aa[100001];
llo bb[100001];
llo pre[100001];
llo tree[4*100001];
void build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=pre[l+1];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb){
		return (llo)1e18;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	llo mid=(l+r)/2;
	return min(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));
}
llo tree2[4*100001];

void build2(llo no,llo l,llo r){
	if(l==r){
		tree2[no]=pre[l+1];
	}
	else{
		llo mid=(l+r)/2;
		build2(no*2+1,l,mid);
		build2(no*2+2,mid+1,r);
		tree2[no]=max(tree2[no*2+1],tree2[no*2+2]);
	}
}
llo query2(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb){
		return -(llo)1e18;
	}
	if(aa<=l and r<=bb){
		return tree2[no];
	}
	llo mid=(l+r)/2;
	return max(query2(no*2+1,l,mid,aa,bb),query2(no*2+2,mid+1,r,aa,bb));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,q;
	cin>>n>>q;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	for(llo i=0;i<n;i++){
		cin>>bb[i];
		aa[i]-=bb[i];
	}
	for(llo i=0;i<n;i++){
		pre[i+1]=pre[i]+aa[i];
	}
/*	for(int i=0;i<n;i++){
		cout<<aa[i]<<":";
	}
	cout<<endl;*/
	build(0,0,n-1);

	build2(0,0,n-1);
	while(q--){
		llo l,r;
		cin>>l>>r;
		l--;
		r--;
		if(pre[r+1]-pre[l]!=0){
			cout<<-1<<endl;
		}
		else {
			llo x=query(0,0,n-1,l,r)-pre[l];
			llo y=query2(0,0,n-1,l,r)-pre[l];
		/*	for(int i=l;i<r;i++){
				cout<<query2(0,0,n-1,i,i)-pre[l]<<",";
			}
			cout<<endl;
			cout<<x<<":"<<y<<endl;*/
			if(y>0){
				cout<<-1<<endl;
			}
			else{
				cout<<abs(x)<<endl;
			}
		}

	}



	


 
 
 
	return 0;
}