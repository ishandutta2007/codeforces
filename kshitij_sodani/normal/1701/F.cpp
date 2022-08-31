#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
//#define endl '\n'

llo tree2[4*200010][3];
llo lazy[4*200010][3];

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<llo,null_type,less<llo>,rb_tree_tag,tree_order_statistics_node_update>
void push(llo no,llo l,llo r){
	if(lazy[no][0]>0){
		tree2[no][0]+=((tree2[no][1]*2+tree2[no][2]*(lazy[no][0]-1))*lazy[no][0])/2;
		tree2[no][1]+=lazy[no][0]*tree2[no][2];
		if(l<r){
			lazy[no*2+1][0]+=lazy[no][0];
			lazy[no*2+2][0]+=lazy[no][0];
		}
		lazy[no][0]=0;
	}	
}

void push2(llo no,llo l,llo r){
	if(lazy[no][1]>0){
		
		llo zz=(tree2[no][1]*2-tree2[no][2]*lazy[no][1]-tree2[no][2])*lazy[no][1];
		zz/=2;
		tree2[no][0]-=zz;
		tree2[no][1]-=lazy[no][1]*tree2[no][2];
		if(l<r){
			lazy[no*2+1][1]+=lazy[no][1];
			lazy[no*2+2][1]+=lazy[no][1];
		}
		lazy[no][1]=0;
	}	
}
void update(llo no,llo l,llo r,llo aa,llo bb){
	push(no,l,r);
	push2(no,l,r);
	
	if(r<aa or l>bb or aa>bb){
		return;
	}
	if(aa<=l and r<=bb){

		lazy[no][0]++;
		
		push(no,l,r);
		push2(no,l,r);

	}
	else{
		llo mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb);
		update(no*2+2,mid+1,r,aa,bb);
		for(llo jj=0;jj<3;jj++){
			tree2[no][jj]=tree2[no*2+1][jj]+tree2[no*2+2][jj];
		}
	}
}
void update2(llo no,llo l,llo r,llo aa,llo bb){
	push(no,l,r);
	push2(no,l,r);

	if(r<aa or l>bb or aa>bb){
		return;
	}
	if(aa<=l and r<=bb){
		lazy[no][1]++;
		push(no,l,r);
		push2(no,l,r);

	}
	else{
		llo mid=(l+r)/2;
		update2(no*2+1,l,mid,aa,bb);
		update2(no*2+2,mid+1,r,aa,bb);
		for(llo jj=0;jj<3;jj++){
			tree2[no][jj]=tree2[no*2+1][jj]+tree2[no*2+2][jj];
		}
	}
}
void update5(llo no,llo l,llo r,llo i,llo j,pair<llo,llo> xx){
	push(no,l,r);
	push2(no,l,r);
	if(i<l or i>r){
		return;
	}
	/*if(i==183395){
		cout<<l<<",,,"<<r<<endl;
	}*/
	if(l==r){
		tree2[no][2]=j;
		tree2[no][0]=xx.a;
		tree2[no][1]=xx.b;
		//cout<<99<<",,,"<<endl;
	}
	else{
		llo mid=(l+r)/2;
		//update5(no*2+1,l,mid,i,j,xx);
		//update5(no*2+2,mid+1,r,i,j,xx);
		if(i<=mid){
			update5(no*2+1,l,mid,i,j,xx);
			push(no*2+2,mid+1,r);
			push2(no*2+2,mid+1,r);
		//	update5(no*2+2,mid+1,r,i,j,xx);

		}
		else{
			if(i<l or i>mid){
				push(no*2+1,l,mid);
				push2(no*2+1,l,mid);
			//	update5(no*2+1,l,mid,i,j,xx);
			}
			//update5(no*2+1,l,mid,i,j,xx);
			update5(no*2+2,mid+1,r,i,j,xx);
			
		}
		for(llo jj=0;jj<3;jj++){
			tree2[no][jj]=tree2[no*2+1][jj]+tree2[no*2+2][jj];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo q,dd;
	cin>>q>>dd;
	set<llo> ss;
	ord tt;
	llo nn=200000;
	//mt19937 rng;
	//rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());
	//vector<llo> kk={14519,125157,139620,86482,183395};

	for(llo i=0;i<q;i++){
		llo aa;
		cin>>aa;
		//aa=rng()%200000;
		/*if(i<kk.size()){
			aa=kk[i];
		}*/
		if(ss.find(aa)==ss.end()){
			ss.insert(aa);
			tt.insert(aa);
			llo xx=tt.order_of_key(aa)-tt.order_of_key(aa-dd);
			update5(0,0,nn,aa,1,{(xx*(xx-1))/2,xx});
			
			update(0,0,nn,aa+1,min(aa+dd,nn));
		}
		else{
			ss.erase(aa);
			tt.erase(aa);
			update5(0,0,nn,aa,0,{0,0});
			update2(0,0,nn,aa+1,min(aa+dd,nn));
		
		}
		/*llo ax=tree2[0][0];
		for(auto j:ss){
			llo xx=tt.order_of_key(j)-tt.order_of_key(j-dd);
			if(xx>0){
				ax-=((xx*(xx-1))/2);
			}
		}*/
		
		//}
		cout<<tree2[0][0]<<endl;
	}






	return 0;
}