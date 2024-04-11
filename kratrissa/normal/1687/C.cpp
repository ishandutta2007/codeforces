#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,m,a[N],b[N];ll ans,sa[N],sb[N];vector<int> lp[N],rp[N],tmp;queue<pair<int,int> > q;set<int> s;
void solve(){
	scanf("%d%d",&n,&m),ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sa[i]=sa[i-1]+a[i];
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),sb[i]=sb[i-1]+b[i];
	for(int i=0;i<=n;i++)lp[i].clear(),rp[i].clear();
	for(int i=1,l,r;i<=m;i++)
		scanf("%d%d",&l,&r),lp[r].push_back(l-1),rp[l-1].push_back(r);
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)
		for(int p:lp[i])if(sa[i]==sb[i]&&sa[p]==sb[p])q.push(make_pair(p,i));
	s.clear();
	for(int i=1;i<=n;i++)if(sa[i]!=sb[i])s.insert(i);
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;q.pop();
		tmp.clear();
		auto itl=s.upper_bound(x),itr=s.upper_bound(y);
		for(auto it=itl;it!=itr;it++)tmp.push_back(*it);
		for(int p:tmp)s.erase(p);
		for(int p:tmp){
			for(int t:lp[p])if(s.find(t)==s.end())q.push(make_pair(t,p));
			for(int t:rp[p])if(s.find(t)==s.end())q.push(make_pair(p,t));
		}
	}
	printf(s.empty()?"Yes\n":"No\n");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}