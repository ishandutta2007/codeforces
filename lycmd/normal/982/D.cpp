#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,ans,v,cur,f[N],sz[N],cnt[N];
pair<int,int>a[N];
set<int>s;
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
void ins(int x){
	if(!cnt[x]++)s.insert(x);
}
void del(int x){
	if(!--cnt[x])s.erase(x);
}
void merge(int x,int y){
	if(x<1||x>n||y<1||y>n)return;
	int fx=find(x),fy=find(y);
	if(fx&&fy&&fx^fy)
		f[fx]=fy,cur--,del(sz[fx]),del(sz[fy]),ins(sz[fy]+=sz[fx]);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].first,a[i].second=i;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int p=a[i].second;
		f[p]=p,cur+=sz[p]=1,ins(1),merge(p-1,p),merge(p,p+1);
		if(s.size()==1&&cur>ans)
			ans=cur,v=a[i].first;
	}
	cout<<v+1<<"\n";
}