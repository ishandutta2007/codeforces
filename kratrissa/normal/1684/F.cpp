#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int read(){
	int res=0;char c=getchar();
	while(c<48)c=getchar();
	while(c>=48)res=res*10+c-48,c=getchar();
	return res;
}
int T,n,m,a[N],A[N],cc,rp[N];vector<int> pos[N];pair<int,int> st[N<<2];
pair<int,int> operator*(pair<int,int> x,pair<int,int> y){return make_pair(max(x.first,y.first),min(x.second,y.second));}
void modify(int l,int r,int x,int L,int R,pair<int,int> v){
	if(l>=L&&r<=R){st[x]=st[x]*v;return;}
	if(l>R||r<L)return;
	int mid=l+r>>1;
	modify(l,mid,x<<1,L,R,v),modify(mid+1,r,x<<1|1,L,R,v);
}
int calcans(int l,int r,int x){
	if(l==r){if(st[x].first<=n)return max(st[x].first-l-1,0);return 1145141;}
	int mid=l+r>>1;
	st[x<<1]=st[x<<1]*st[x],st[x<<1|1]=st[x<<1|1]*st[x];
	return min(calcans(l,mid,x<<1),calcans(mid+1,r,x<<1|1));
}
void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)A[i]=a[i]=read();
	sort(A+1,A+n+1),cc=unique(A+1,A+n+1)-A-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(A+1,A+cc+1,a[i])-A;
	for(int i=1;i<=n;i++)pos[i].clear(),rp[i]=0;
	for(int i=1;i<=n;i++)pos[a[i]].push_back(i);
	for(int i=1,l,r;i<=m;i++)l=read(),r=read(),rp[l]=max(rp[l],r);
	for(int i=2;i<=n;i++)rp[i]=max(rp[i],rp[i-1]);
	fill(st,st+(n<<2)+1,make_pair(0,n));
	for(int i=1;i<=n;i++)if(rp[i]>=i){
		int l=lower_bound(pos[a[i]].begin(),pos[a[i]].end(),i)-pos[a[i]].begin(),r=upper_bound(pos[a[i]].begin(),pos[a[i]].end(),rp[i])-pos[a[i]].begin()-1,tr=pos[a[i]][r];
		if(l==r)continue;
		int lm=pos[a[i]][l+1],rm=pos[a[i]][r-1];
		modify(0,n,1,0,i-1,make_pair(rm+1,n)),modify(0,n,1,i,lm-1,make_pair(tr+1,n)),modify(0,n,1,lm,n,make_pair(n+1,n));
	}
	printf("%d\n",calcans(0,n,1));
}
int main(){
	T=read();
	while(T--)solve();
	return 0;
}