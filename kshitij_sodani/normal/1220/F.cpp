//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n;
llo it[2*200001];
llo lazy[8*200001];
llo tree[8*200001];
llo le[400001][20];
llo re[400001][20];
void push(llo no,llo l,llo r){
	tree[no]+=lazy[no];
	if(l<r){
		lazy[no*2+1]+=lazy[no];
		lazy[no*2+2]+=lazy[no];
	}
	lazy[no]=0;
}
/*llo query(llo no,llo l,llo r,llo aa,llo bb){
	push(no,l,r);
	if(r<aa or l>bb){
		return 0;
	}
	else if(aa<=l and r<=bb){
		return tree[no];
	}
	else{
		llo mid=(l+r)/2;
		llo x=query(no*2+1,l,mid,aa,bb);
		llo y=query(no*2+2,mid+1,r,aa,bb);
		return max(x,y);
	}
}*/
void update(llo no,llo l,llo r,llo aa,llo bb,llo val){
	push(no,l,r);
	if(bb<l or r<aa){
		return;
	}
	if(aa<=l and r<=bb){
		lazy[no]+=val;
		push(no,l,r);
	}
	else{
		llo mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,val);
		update(no*2+2,mid+1,r,aa,bb,val);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
/*llo re(llo i){
	llo ind=i;
	for(llo j=19;j>=0;j--){
		if(ind+(1<<j)<2*n){
			pair<llo,llo> xx=query(0,0,2*n-1,i,ind+(1<<j));
			if(xx.a>=it[i%n]){
				ind+=(1<<j);
			}
		}
	}
	return ind+1;
}
llo le(llo i){
	llo ind=i;
	for(llo j=19;j>=0;j--){
		if(ind-(1<<j)>=0){
			pair<llo,llo> xx=query(0,0,2*n-1,ind-(1<<j),i);
			if(xx.a>=it[i%n]){
				ind-=(1<<j);
			}
		}
	}
	return ind-1;
}*/
llo aa(llo i,llo x){
	llo co=0;
	for(llo j=19;j>=0;j--){
		if(re[i][j]==-1){
			continue;
		}
		if(re[i][j]<=x){
			i=re[i][j];
			co+=(1<<j);
		}
	}
	return co;
}
llo bb(llo i,llo x){
	llo co=0;
	for(llo j=19;j>=0;j--){
		if(le[i][j]==-1){
			continue;
		}
		if(le[i][j]>=x){
			i=le[i][j];
			co+=(1<<j);
		}
	}
	return co;
}
llo query(llo no,llo l,llo r,llo i){
	push(no,l,r);
	if(l==r){
		return tree[no];
	}
	else{
		int mid=(l+r)/2;
		
		if(i<=mid){
			llo x=query(no*2+1,l,mid,i);
			push(no*2+2,mid+1,r);
			tree[no]=max(tree[no*2+1],tree[no*2+2]);
			return x;
		}
		else{
		 	llo y= query(no*2+2,mid+1,r,i);
		 	push(no*2+1,l,mid);
		 	tree[no]=max(tree[no*2+1],tree[no*2+2]);
		 	return y;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<llo,llo>> ss;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		it[i+n]=it[i];
	}
	if(n==1){
		cout<<"1 0"<<endl;
		return 0;
	}
	
	for(llo i=0;i<2*n;i++){
		while(ss.size()){
			if(ss.back().a>it[i]){
				ss.pop_back();
			}
			else{
				break;
			}
		}
		if(ss.size()){
			le[i][0]=ss.back().b;
		}
		else{
			le[i][0]=-1;
		}
		ss.pb({it[i],i});
		//cout<<le[i][0]<<"<";
	}
	//cout<<endl;
	ss.clear();
	for(llo i=2*n-1;i>=0;i--){
		while(ss.size()){
			if(ss.back().a>it[i]){
				ss.pop_back();
			}
			else{
				break;
			}
		}
		if(ss.size()){
			re[i][0]=ss.back().b;
		}
		else{
			re[i][0]=-1;
		}
		ss.pb({it[i],i});
	}
	/*for(int i=0;i<2*n;i++){
		cout<<le[i][0]<<",";
	}
	cout<<endl;*/
	ss.clear();
	for(llo j=1;j<20;j++){
		for(llo i=0;i<2*n;i++){

			if(le[i][j-1]==-1){
				le[i][j]=-1;
			}
			else{
				/*if(i==6 and j==1){
					cout<<i<<".."<<j-1<<endl;
					cout<<le[i][j-1]<<":"<<le[le[i][j-1]][j-1]<<endl;
				}*/
				le[i][j]=le[le[i][j-1]][j-1];
			}
			if(re[i][j-1]==-1){
				re[i][j]=-1;
			}
			else{
				re[i][j]=re[re[i][j-1]][j-1];
			}
		}
	}
/*	cout<<le[6][0]<<endl;
	cout<<le[5][0]<<endl;
	cout<<le[6][1]<<endl;*/
	for(llo i=0;i<n;i++){
		llo x=aa(i,n-1);
		update(0,0,2*n-1,i,i,x);
		x=bb(i,0);
		update(0,0,2*n-1,i,i,x);
	}
	pair<llo,llo> ans={n+1,0};
/*	for(int j=0;j<2*n;j++){
		cout<<query(0,0,2*n-1,j)<<".";
	}
	cout<<endl;*/
	/*for(int j=0;j<2*n;j++){
				cout<<query(0,0,2*n-1,j)<<".";
			}
			cout<<endl;*/
	for(llo i=0;i<n;i++){
		if(i>0){
			llo xx=i-1+n-1;
			if(re[i-1][0]!=-1){
				xx=min(xx,re[i-1][0]-1);
			}
			if(i<=xx){
				update(0,0,2*n-1,i,xx,-1);
			}
			llo yy=aa(i-1,i-1+n-1);
			update(0,0,2*n-1,i-1,i-1,-yy);
			llo zz=bb(i+n-1,i);
			//cout<<zz<<"?"<<endl;

			update(0,0,2*n-1,i+n-1,i+n-1,zz);

			xx=i;
			xx=max(xx,le[i+n-1][0]+1);
			
			if(xx<i+n-1){
				update(0,0,2*n-1,xx,i+n-2,1);
			}
		/*	for(int j=0;j<2*n;j++){
				cout<<query(0,0,2*n-1,j)<<".";
			}
			cout<<endl;
			cout<<xx<<endl;*/
		}
	/*	for(int j=0;j<2*n;j++){
			cout<<query(0,0,2*n-1,j)<<".";
		}
		cout<<endl;*/
		ans=min(ans,{tree[0],i});
	//	cout<<tree[0]<<":"<<i<<endl;
	}
	cout<<ans.a+1<<" "<<ans.b<<endl;







 
 
	return 0;
}