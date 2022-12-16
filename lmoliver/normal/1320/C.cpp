#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=200200;
const int V=1001001;
struct SegTree{
	int mx[4*V],tag[4*V];
	SegTree(){
		for(int i=0;i<4*V;i++){
			mx[i]=INT_MIN;
		}
	}
#define LS (id<<1)
#define RS ((id<<1)|1)
	void upd(int id){
		mx[id]=max(mx[LS],mx[RS])+tag[id];
	}
	void set(int x,int v,int ll,int rr,int id){
		// if(id==1)cerr<<x<<" "<<v<<endl;
		if(ll==rr){
			mx[id]=v;
		}
		else{
			int mid=(ll+rr)>>1;
			if(x<=mid){
				set(x,v,ll,mid,LS);
			}
			else{
				set(x,v,mid+1,rr,RS);
			}
			upd(id);
		}
	}
	void mk(int id,int v){
		// cerr<<id<<" "<<v<<endl;
		tag[id]+=v;
		mx[id]+=v;
	}
	void add(int l,int r,int v,int ll,int rr,int id){
		// if(id==1)cerr<<l<<" "<<r<<" "<<v<<endl;
		if(l<=ll&&rr<=r){
			mk(id,v);
		}
		else if(r>=ll&&rr>=l){
			int mid=(ll+rr)>>1;
			add(l,r,v,ll,mid,LS);
			add(l,r,v,mid+1,rr,RS);
			upd(id);
		}
	}
	int query(){
		// cerr<<"? "<<mx[1]<<endl;
		return mx[1];
	}
};
SegTree tr;
typedef pair<int,int> P;
int n,m,p;
P weps[N],arms[N];
pair<P,int> mons[N];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>p;
	for(int i=0;i<n;i++){
		cin>>weps[i].first>>weps[i].second;
	}
	for(int i=0;i<m;i++){
		cin>>arms[i].first>>arms[i].second;
	}
	for(int i=0;i<p;i++){
		cin>>mons[i].first.first>>mons[i].first.second>>mons[i].second;
	}
	sort(weps,weps+n);
	sort(arms,arms+m);
	sort(mons,mons+p);
	for(int i=m-1;i>=0;i--){
		tr.set(arms[i].first,-arms[i].second,1,V,1);
	}
	int cur=0;
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		// cerr<<"wep "<<i<<endl;
		while(cur<p&&weps[i].first>mons[cur].first.first){
			tr.add(mons[cur].first.second+1,V,mons[cur].second,1,V,1);
			cur++;
		}
		ans=max(ans,tr.query()-weps[i].second);
	}
	cout<<ans<<endl;
	return 0;
}