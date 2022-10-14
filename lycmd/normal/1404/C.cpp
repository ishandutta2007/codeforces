#include<bits/stdc++.h>
using namespace std;
int const N=300010;
int n,q,a[N],tr[N],ans[N];
struct node{
	int l,r,id;
	int operator<(const node&rhs)const{
		return r<rhs.r;
	}
};
vector<node>vq;
void add(int x,int y){
	for(;x<=n;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	int res=0;
	for(;x;x&=x-1)res+=tr[x];
	return res;
}
int get(int x){
	int res=0;
	for(int i=18;~i;i--)
		if(res+(1<<i)<=n&&x>tr[res+(1<<i)])
			x-=tr[res+=1<<i];
	return res+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]=i-a[i];
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		vq.push_back({1+x,n-y,i});
	}
	sort(vq.begin(),vq.end());
	int p=1;
	for(auto i:vq){
		for(;p<=i.r;p++)
			add(a[p]<0?1:min(p+1,get(p-a[p])),1);
		ans[i.id]=i.r-ask(i.l);
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}