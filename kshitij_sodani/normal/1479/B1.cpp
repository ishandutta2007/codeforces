//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int n;
int it[100010];
int tree[4*100010];
int lazy[4*100010];
int ind[100010];
int dp[100010];
pair<int,int> ac[100010];
void push(int no,int l,int r){
	tree[no]+=lazy[no];
	if(l<r){
		lazy[no*2+1]+=lazy[no];
		lazy[no*2+2]+=lazy[no];
	}
	lazy[no]=0;
}
void update(int no,int l,int r,int aa,int bb,int cc){
	lazy[no]+=cc;
	push(no,l,r);
}
void update2(int no,int l,int r,int i,int j){
	push(no,l,r);
	if(l==r){
		tree[no]=j;
	}
	else{
		int mid=(l+r)/2;
		if(i<=mid){
			update2(no*2+1,l,mid,i,j);
			push(no*2+2,mid+1,r);
		}
		else{
			update2(no*2+2,mid+1,r,i,j);
			push(no*2+1,l,mid);
		}
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
int query(int no,int l,int r,int aa,int bb){
	push(no,l,r);
	if(l>bb or r<aa){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	else{
		int mid=(l+r)/2;
		int x=query(no*2+1,l,mid,aa,bb);
		int y=query(no*2+2,mid+1,r,aa,bb);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
		return max(x,y);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<int,int>> ss;
	for(int i=1;i<=n;i++){
		cin>>it[i];
		ss.pb({it[i],i});
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<=n;i++){
		ac[i]={-1,-1};
	}
	sort(ss.begin(),ss.end());
	/*for(auto j:ss){
		cout<<j.a<<":"<<j.b<<endl;
	}*/
	for(int i=0;i<n;i++){
		ind[ss[i].b]=i+1;
		//cout<<i<<":"<<endl;
		if(ac[ss[i].a].a==-1){
			ac[ss[i].a].a=i+1;
		}
		ac[ss[i].a].b=i+1;
	}
	//return 0;

	for(int i=0;i<=4*(n+1);i++){
		tree[i]=0;
	}
	it[0]=-1;
	ind[0]=0;
	//update2(0,0,n,0,1);
	for(int i=1;i<=n;i++){
		//break;
		//cout<<i<<"<<<<<<"<<endl;
		if(i>1){
			int x=0;
			x=max(x,query(0,0,n,ac[it[i]].a,ac[it[i]].b));
			int pp=query(0,0,n,ac[it[i]].a,ac[it[i]].b);
			//cout<<pp<<":"<<endl;
			if(ac[it[i]].a>0){
				x=max(x,query(0,0,n,0,ac[it[i]].a-1)+1);
				//cout<<query(0,0,n,0,ac[it[i]].a-1)+1<<",,"<<endl;
			}
			if(ac[it[i]].b<n){
				x=max(x,query(0,0,n,ac[it[i]].b+1,n)+1);
			//	cout<<query(0,0,n,ac[it[i]].b+1,n)+1<<",,"<<endl;
			}

			dp[i-1]=x;
		}
		if(it[i]!=it[i-1]){
			update(0,0,n,0,n,1);
		}
		if(i>1){
			//cout<<ind[i-1]<<"??"<<endl;
			update2(0,0,n,ind[i-1],dp[i-1]);
		}
		/*for(int j=0;j<i;j++){
			cout<<query(0,0,n,ind[j+1],ind[j+1])<<",";
		}
		cout<<endl;*/
	//	break;
	}
	int ans=0;
	ans=query(0,0,n,0,n);
	cout<<ans<<endl;











 
	return 0;
}