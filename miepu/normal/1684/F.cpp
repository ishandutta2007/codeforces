#include<bits/stdc++.h>
#define int long long
#define all(k) k.begin(),k.end()
const int N=1000005;
using namespace std;

int n,m;
int a[N],b[N],mx[N];
int sm[N],bg[N];
int pr[N],sf[N];
vector<int> pos[N];

struct sgt{
	#define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    int mx[N];
    void clear(int k,int l,int r){
    	mx[k]=0;
		if(l^r)clear(ls,l,mid),clear(rs,mid+1,r);
	}
    void psh(int k,int l,int r,int x,int y,int p){
    	if(r<x||l>y)return ;
    	if(l>=x&&r<=y){
    		mx[k]=max(mx[k],p);
    		return ;
		}
		psh(ls,l,mid,x,y,p);
		psh(rs,mid+1,r,x,y,p);
	}
	int get(int k,int l,int r,int x){
		int res=mx[k];
		if(l==r)return res;
		if(x<=mid) res=max(res,get(ls,l,mid,x));
		else res=max(res,get(rs,mid+1,r,x));
		return res;
	}
}T;

void solve(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)pos[i].clear();
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n);
	int sz=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+1+sz,a[i])-b;
	for(int i=1;i<=n;i++){
		pos[a[i]].push_back(i);
	}
	
	T.clear(1,1,n);
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		T.psh(1,1,n,l,r,r);
	}
	
	for(int i=1;i<=n;i++)
		mx[i]=T.get(1,1,n,i);
	for(int i=1;i<=n;i++){
		auto it=upper_bound(all(pos[a[i]]),i);
		if(it==pos[a[i]].end()||*it>mx[i]){
			sm[i]=1e9;
			bg[i]=-1;
			continue;
		}
		sm[i]=*it;
		it=--upper_bound(all(pos[a[i]]),mx[i]);
		bg[i]=*it;
	}
	
	int R=n;
	while(sm[R]==1e9)R--;
	
	int res=n;
	for(int i=1,r=0,L=n+1;i<=n;i++){
		if(i-1)L=min(L,sm[i-1]);
		if(i>L)break;
		r=max(r,bg[i-1]);
		res=min(res,max(R,r)-i+1);
	}
	
	cout<<max(res,0ll)<<endl;
	
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}