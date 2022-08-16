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
llo it[200001];
llo tree[800001];
llo tree2[800001];
llo lazy[800001];
void build(llo no,llo l,llo r){
	lazy[no]=-1;
	if(l==r){
		tree[no]=it[l];
		tree2[no]=it[l];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=tree[no*2+1]+tree[no*2+2];
		tree2[no]=min(tree2[no*2+1],tree2[no*2+2]);
	}
}
void push(llo no,llo l,llo r){
	if(lazy[no]!=-1){
		tree[no]=lazy[no]*(r-l+1);
		tree2[no]=lazy[no];
		if(l<r){
			lazy[no*2+1]=lazy[no];
			lazy[no*2+2]=lazy[no];
		}
		lazy[no]=-1;
	}
}
void update(llo no,llo l,llo r,llo aa,llo bb,llo val){
	push(no,l,r);
	if(l>bb or r<aa){
		return;
	}
	if(aa<=l and r<=bb){
		tree[no]=val*(r-l+1);
		tree2[no]=val;
		if(l<r){
			lazy[no*2+1]=val;
			lazy[no*2+2]=val;
		}
	}
	else{
		llo mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,val);
		update(no*2+2,mid+1,r,aa,bb,val);

		tree[no]=tree[no*2+1]+tree[no*2+2];
		tree2[no]=min(tree2[no*2+1],tree2[no*2+2]);
	}
}
llo find(llo no,llo l,llo r,llo aa,llo bb){
	push(no,l,r);
	if(r<aa){
		return -1;
	}
	//cout<<l<<",,,"<<r<<",,"<<tree[no]<<endl;
	if(l>=aa){
		if(tree2[no]>bb){
			return -1;
		}
		if(l==r){
			return l;
		}
		else{
			int mid=(l+r)/2;
			push(no*2+1,l,mid);
			if(tree2[no*2+1]>bb){
				return find(no*2+2,mid+1,r,aa,bb);
			}
			else{
				return find(no*2+1,l,mid,aa,bb);
			}
		}
	}
	if(l==r){
		if(tree2[no]<=bb){
			return l;
		}
		else{
			return -1;
		}
	}
		llo mid=(l+r)/2;
		llo x=find(no*2+1,l,mid,aa,bb);
		if(x!=-1){
			return x;
		}
		return find(no*2+2,mid+1,r,aa,bb);
	
}
vector<pair<llo,pair<llo,llo>>> ss;
void find2(llo no,llo l,llo r,llo aa,llo bb){
	push(no,l,r);
	if(r<aa){
		return ;
	}
	if(l>=aa and r<=n-1){
		ss.pb({no,{l,r}});
		return;

	}

		llo mid=(l+r)/2;
		


			find2(no*2+1,l,mid,aa,bb);
			find2(no*2+2,mid+1,r,aa,bb);


		tree[no]=tree[no*2+1]+tree[no*2+2];
		tree2[no]=min(tree2[no*2+1],tree2[no*2+2]);
}
pair<llo,llo> find3(llo no,llo l,llo r,llo bb){
		push(no,l,r);
		if(l==r){
			if(tree[no]<=bb){
				return {r,bb-tree[no]};
			}
			else{
				return {l-1,bb};
			}
		}
		llo mid=(l+r)/2;
		push(no*2+1,l,mid);


		if(bb>=tree[no*2+1]){
			pair<int,int> xx=find3(no*2+2,mid+1,r,bb-tree[no*2+1]);

			return xx;
		}
		else{
			pair<int,int> xx=find3(no*2+1,l,mid,bb);
			return xx;
		}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	build(0,0,n-1);
	llo ac=it[n-1];
	while(q--){
		llo t,aa,bb;
		cin>>t>>aa>>bb;
		if(t==1){
			aa--;
			if(aa==n-1){
				ac=max(ac,bb);
			}
			if(bb>=ac){
				llo ind=find(0,0,n-1,0,bb);
				if(ind<=aa){
					update(0,0,n-1,ind,aa,bb);
				}
			}
		}
		else{
			aa--;
			llo ind=aa;
			llo ans=0;

			while(ind<n and bb>=ac){
				llo de=bb;
				ind=find(0,0,n-1,ind,bb);
			//	cout<<ind<<":"<<endl;
				ss.clear();
				find2(0,0,n-1,ind,bb);
				llo ind2=ind;
				for(auto j:ss){
					if(tree[j.a]<=bb){
						bb-=tree[j.a];
						ind2=j.b.b;
					}
					else{
						pair<llo,llo> ind3=find3(j.a,j.b.a,j.b.b,bb);
						ind2=ind3.a;
						bb=ind3.b;
						break;
					}
				}
		//		cout<<ind2<<",,"<<bb<<endl;
				ans+=ind2-ind+1;
				ind=ind2+1;
			//	break;
			}

			cout<<ans<<endl;

		}
	}




 
 
	return 0;
}