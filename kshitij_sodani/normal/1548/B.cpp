//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[200001];
llo pre[200001];
llo tree[4*200001];
void build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=pre[l];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=__gcd(tree[no*2+1],tree[no*2+2]);
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	llo mid=(l+r)/2;
	return __gcd(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;

	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo ans=1;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		for(llo i=0;i<n-1;i++){
			pre[i]=abs(it[i]-it[i+1]);
		}
		llo ind=0;
		build(0,0,n-2);

		for(llo i=0;i<n-1;i++){
			ind=max(ind,i);
			while(query(0,0,n-2,i,ind)>1 and ind+1<=n-2){
				if(query(0,0,n-2,i,ind+1)>1){
					ind++;
				}
				else{
					break;
				}
			}
			if(ind==i and pre[i]==1){

				

			}
			else{
				ans=max(ans,ind-i+2);
			}	
			//cout<<i<<":"<<ind<<endl;
		}
		cout<<ans<<endl;


	}
 
 

 
 
 
	return 0;
}