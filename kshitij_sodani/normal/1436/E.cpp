//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int vis[100010];
int n;
int it[100001];
vector<int> pre[100010];
int tree[100001*4];
int lazy[100001*4];
int tt[100001];
void build(int no,int l,int r){
	lazy[no]=-1;
	if(l==r){
		tree[no]=l;
		//tt[l]=l;
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
void push(int no,int l,int r){
	if(lazy[no]==-1){
		return;
	}
	tree[no]=lazy[no];
	if(l<r){
		lazy[no*2+1]=lazy[no];
		lazy[no*2+2]=lazy[no];
	}
	lazy[no]=-1;
}
int query(int no,int l,int r,int i){
	//return tt[i];
		push(no,l,r);
	
	if(l==r){
		return tree[no];
	}
	else{
		int mid=(l+r)/2;
		push(no*2+1,l,mid);
		push(no*2+2,mid+1,r);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
		if(i<=mid){
			return query(no*2+1,l,mid,i);
		}
		else{
			return query(no*2+2,mid+1,r,i);
		}
	}
}

void update(int no,int l,int r,int aa,int bb,int i){
	/*for(int j=aa;j<=bb;j++){
		tt[j]=i;
		
	}

	return;*/
	push(no,l,r);
	if(aa>r or bb<l){
		return;
	}
	if(aa<=l and r<=bb){
		tree[no]=i;
		if(l<r){
			lazy[no*2+1]=i;
			lazy[no*2+2]=i;
		}
	}
	else{
		int mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,i);
		update(no*2+2,mid+1,r,aa,bb,i);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
int query2(int no,int l,int r,int i){

	push(no,l,r);
	if(l==r){
		if(tree[no]<i){
			return r;
		}
		return r-1;
	}
	else{
		int mid=(l+r)/2;
		push(no*2+1,l,mid);
		push(no*2+2,mid+1,r);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
		if(tree[no*2+1]<i){
			return query2(no*2+2,mid+1,r,i);
		}
		return query2(no*2+1,l,mid,i);
	}




}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
		pre[it[i]].pb(i);
	}
	int mi=n-1;
	build(0,0,n-1);
	for(int i=1;i<=n+2;i++){
		if(pre[i].size()){
			int st=0;
			for(int j=0;j<pre[i].size()-1;j++){
				if(pre[i][j]+1<=mi and pre[i][j]+1<pre[i][j+1]){
					if(query(0,0,n-1,pre[i][j]+1)<=pre[i][j+1]-1){
						st=1;
						break;
					}
				}
			}
		//	if(pre[i].back())
			if(pre[i].back()+1<=mi){
				st=1;
			}
			if(query(0,0,n-1,0)<pre[i][0]){
				st=1;
			}
			if(st==0){
				cout<<i<<endl;
				return 0;
			}
			for(int j=0;j<pre[i].size();j++){
				int le=0;
				if(j>0){
					le=pre[i][j-1]+1;
				}
				int re=pre[i][j]-1;
				if(le<=re){
					int ind=query2(0,0,n-1,pre[i][j]);
					ind=min(ind,re);
					//if(query(0,0,n-1,le)<pre[i][j]){
						/*for(int jj=re;jj>=le;jj--){
							if(query(0,0,n-1,jj)>=pre[i][j]){
								ind--;
							}
						}*/
						ind=min(ind,mi);
						if(ind>=le){
							//cout<<le<<":"<<ind<<":"<<pre[i][j]<<endl;
							update(0,0,n-1,le,ind,pre[i][j]);
						}
					//}
				}
			}
		/*	for(int j=0;j<n;j++){
				cout<<query(0,0,n-1,j)<<",";
			}
			cout<<endl;
*/

		}
		else{
			cout<<i+1<<endl;
			return 0;
		}
		mi=min(mi,pre[i].back());
	}















 
	return 0;
}