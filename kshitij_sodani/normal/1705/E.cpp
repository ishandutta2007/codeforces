#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
 
llo it[200001];
 
llo pre[220001];
llo tree[4*220001];
llo lazy[4*220001];
llo ma=210000;
 
/*int uu(int i,int j){
	while(i<=ma){
		tree[i]+=j;
		i+=(i&-i);
	}
 
}
int ss(int i){
	int su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}*/
void build(int no,int l,int r){
	lazy[no]=-1;
	if(l==r){
		/*if(pre[l]>0){
			uu(l,pre[l]);
		}*/
		tree[no]=pre[l];
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=tree[no*2+1]+tree[no*2+2];
	}
}
void push(int no,int l,int r){
	if(lazy[no]>=0){
		tree[no]=lazy[no]*(r-l+1);
		if(l<r){
			lazy[no*2+1]=lazy[no];
			lazy[no*2+2]=lazy[no];
		}
		lazy[no]=-1;
	}
}
void update(int no,int l,int r,int aa,int bb,int cc){
 
	push(no,l,r);
	if(r<aa or l>bb or aa>bb){
		return;
	}
	if(aa<=l and r<=bb){
		lazy[no]=cc;
		push(no,l,r);
	}
	else{
		int mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,cc);
		update(no*2+2,mid+1,r,aa,bb,cc);
		tree[no]=tree[no*2+1]+tree[no*2+2];
	}
}
int query(int no,int l,int r,int aa,int bb,int cc){
 
	push(no,l,r);
	if(r<aa or l>bb or aa>bb){
		return -1;
	}
	if(aa<=l and r<=bb){
		int mid=(l+r)/2;
		/*if(l>=3 and r<=8){
			cout<<l<<":"<<r<<":"<<tree[no]<<":"<<cc<<endl;
		}*/
		if(l==r){
			if(tree[no]!=cc){
				return l;
			}
			else{
				return -1;
			}
		}
		push(no*2+1,l,mid);
		if(tree[no*2+1]!=cc*(mid-l+1)){
			push(no*2+2,mid+1,r);
			return query(no*2+1,l,mid,aa,bb,cc);
		}
		return query(no*2+2,mid+1,r,aa,bb,cc);
	}
	else{
		int mid=(l+r)/2;
		int x=query(no*2+1,l,mid,aa,bb,cc);
		if(x>=0){
			push(no*2+2,mid+1,r);

			return x;
		}
		return query(no*2+2,mid+1,r,aa,bb,cc);
	}
}
int query2(int no,int l,int r,int aa,int bb,int cc){
 
	push(no,l,r);
	if(r<aa or l>bb or aa>bb){
		return -1;
	}
	if(aa<=l and r<=bb){
		int mid=(l+r)/2;
 
		if(l==r){
			if(tree[no]!=cc){
				return l;
			}
			else{
				return -1;
			}
		}
		push(no*2+2,mid+1,r);
		if(tree[no*2+2]!=cc*(r-mid)){
			push(no*2+1,l,mid);
			return query2(no*2+2,mid+1,r,aa,bb,cc);
			
		}
		return query2(no*2+1,l,mid,aa,bb,cc);
		
	}
	else{
		int mid=(l+r)/2;
		int x=query2(no*2+2,mid+1,r,aa,bb,cc);
		if(x>=0){
			push(no*2+1,l,mid);
			return x;
		}
		return query2(no*2+1,l,mid,aa,bb,cc);
	}
}
void remove(int aa){

	int ind=query(0,0,ma,aa,ma,0);
	assert(ind>=0);
	//cout<<ind<<":"<<endl;
	update(0,0,ma,ind,ind,0);
	if(ind>aa){
		update(0,0,ma,aa,ind-1,1);
	}
}
void add(int aa){
	int ind=query(0,0,ma,aa,ma,1);
	assert(ind>=0);
	update(0,0,ma,ind,ind,1);
	if(ind>aa){
		update(0,0,ma,aa,ind-1,0);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,q;
	cin>>n>>q;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		pre[it[i]]++;
	}
	
	for(llo i=1;i<ma;i++){
		pre[i+1]+=(pre[i]/2);
		pre[i]%=2;
	}
	build(0,0,210000);

	while(q--){
		llo i,jj;
		cin>>i>>jj;
		i--;
		llo x=it[i];
		remove(x);
		it[i]=jj;
		add(jj);
		int ind=query2(0,0,ma,0,ma,0);
		cout<<ind<<endl;
 
	}
 
 
 
 
	return 0;
}