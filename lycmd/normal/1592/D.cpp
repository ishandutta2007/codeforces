#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int n,cur,seq[N];
vector<int>e[N],t;
void dfs(int x,int fa){
	seq[++cur]=x;
	for(int y:e[x])
		if(y^fa)dfs(y,x),seq[++cur]=x;
}
int ask(int l,int r){
	t.clear();
	for(int i=l;i<=r;i++)
		t.push_back(seq[i]);
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	cout<<"? "<<t.size();
	for(int x:t)cout<<" "<<x;
	cout<<endl;
	cin>>l;return l;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	int l=1,r=cur,pre=ask(1,cur);
	while(l<r-1){
		int mid=(l+r)>>1,res=ask(l,mid);
		if(res==pre)r=mid;else l=mid;
	}
	cout<<"! "<<seq[l]<<" "<<seq[r]<<endl;
}