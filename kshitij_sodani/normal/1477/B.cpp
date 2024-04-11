//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;
int it[200001];
int tree[4*200001];
int lazy[4*200001];
int tt[200001];
void push(int no,int l,int r){
	if(lazy[no]>-1){
		tree[no]=lazy[no]*(r-l+1);
		if(l<r){
			lazy[no*2+1]=lazy[no];
			lazy[no*2+2]=lazy[no];
		}
		lazy[no]=-1;
	}
}
void build(int no,int l,int r){
	lazy[no]=-1;
	if(l==r){
		tree[no]=it[l];
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=tree[no*2+1]+tree[no*2+2];
	}
}
int query(int no,int l,int r,int aa,int bb){
	push(no,l,r);
	if(r<aa or l>bb){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	else{
		int mid=(l+r)/2;
		int x=query(no*2+1,l,mid,aa,bb);
		int y=query(no*2+2,mid+1,r,aa,bb);
		tree[no]=tree[no*2+1]+tree[no*2+2];
		return x+y;
	}
}
void update(int no,int l,int r,int aa,int bb,int cc){
	push(no,l,r);
	if(r<aa or l>bb){
		return ;
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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		string ss;
		cin>>ss;
		for(int i=0;i<n;i++){
			tt[i]=ss[i]-'0';
		}
		string s;
		cin>>s;
		for(int i=0;i<n;i++){
			it[i]=s[i]-'0';
		}
		vector<pair<int,int>> qq;
		for(int i=0;i<q;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			qq.pb({aa,bb});
		}
		build(0,0,n-1);
		int st=1;
		reverse(qq.begin(),qq.end());
		for(auto j:qq){
			int x=query(0,0,n-1,j.a,j.b);
			if(x*2==j.b-j.a+1){
				st=0;
				break;
			}
			else{
				if(x*2<j.b-j.a+1){
					update(0,0,n-1,j.a,j.b,0);
				}
				else{
					update(0,0,n-1,j.a,j.b,1);
				}
			}
			/*for(int i=0;i<n;i++){
				cout<<query(0,0,n-1,i,i)<<",";
			}
			cout<<endl;*/
		}
		for(int i=0;i<n;i++){
			if((query(0,0,n-1,i,i)!=tt[i])){
				st=0;
			}
		}
		if(st==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}




	}













 
	return 0;
}