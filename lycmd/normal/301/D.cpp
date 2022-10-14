#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,q,a[N],pos[N],tr[N],ans[N];
vector<int>e[N];
struct node{
	int l,r,id;
	int operator<(const node&rhs)const{
		return r<rhs.r;
	}
};
vector<node>vq;
void add(int x,int y){
	for(x++;x<N;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	int res=0;
	for(x++;x;x&=x-1)res+=tr[x];
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i],pos[a[i]]=i;
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		vq.push_back({l,r,i});
	}
	for(int i=1;i<=n;i++)
		for(int j=a[i];j<=n;j+=a[i]){
			int x=i,y=pos[j];
			if(x<y)swap(x,y);
			e[x].push_back(y);
		}
	sort(vq.begin(),vq.end());
	int p=1;
	for(auto i:vq){
		for(;p<=i.r;p++)
			for(int j:e[p])
				add(j,1);
		ans[i.id]=ask(i.r)-ask(i.l-1);
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}