//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,k;
llo it[200001];
llo ans=-1;
llo tree[450000*4];
llo lazy[450000*4];
void push(llo no,llo l,llo r){
	if(lazy[no]){
		tree[no]+=lazy[no]*(r-l+1);;
		if(l<r){
			lazy[no*2+1]+=lazy[no];
			lazy[no*2+2]+=lazy[no];
		}
		lazy[no]=0;
	}
}
void update(llo no,llo l,llo r,llo aa,llo bb,llo cc){
	push(no,l,r);
	if(l>bb or r<aa){
		return;
	}
	if(aa<=l and r<=bb){
		tree[no]+=cc*(r-l+1);
		if(l<r){
			lazy[no*2+1]+=cc;
			lazy[no*2+2]+=cc;
		}
	}
	else{
		llo mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,cc);
		update(no*2+2,mid+1,r,aa,bb,cc);
		tree[no]=tree[no*2+1]+tree[no*2+2];
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	push(no,l,r);
	if(l>bb or r<aa){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	else{
		llo mid=(l+r)/2;
		return query(no*2+1,l,mid,aa,bb)+query(no*2+2,mid+1,r,aa,bb);
	}
}
void remin(llo aa){
	if(ans==-1){
		ans=aa;
	}
	ans=min(ans,aa);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	sort(it,it+n);
/*
	u(1,1);
	u(2,-1);
	cout<<ss(2)<<endl;*/
	//u(1,1);
	update(0,0,450000,0,0,1);
	llo cur=0;
	for(llo i=n-1;i>=0;i--){
		while(query(0,0,450000,0,cur)==0){
			cur++;
		}


		update(0,0,450000,cur,cur,-1);
	//	cout<<ss(2)<<endl;
		//cout<<cur<<":"<<endl;
		llo le=(it[i]-1)/2;
		llo le2=it[i]-1-le;
	//	cout<<cur<<":"<<endl;
		if(le>0){
			update(0,0,450000,cur+2,cur+2+le-1,1);
		}
		if(le2>0){
			update(0,0,450000,cur+2,cur+2+le2-1,1);
		}
		//cout<<ss(10)<<endl;
		llo low=0;
		llo high=450000;
		while(low<high-1){
			llo mid=(low+high)/2;
			if(query(0,0,450000,0,mid)>=k){
				high=mid;
			}
			else{
				low=mid;
			}
		}
		for(llo j=low;j<=high;j++){
			if(query(0,0,450000,0,j)>=k){
				remin(j);
			}
		}
		/*for(llo j=0;j<=450000;j++){
			if(query(0,0,450000,0,j)>=k){
			//	cout<<j<<endl;
				remin(j);
				break;
			}
		}*/
	}




	cout<<ans<<endl;
 
	return 0;
}