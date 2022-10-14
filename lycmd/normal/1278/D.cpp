#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,l[N],r[N],f[N],ord[N];
struct event{
	int pos,id,op;
	int operator<(const event&rhs)const{
		return pos<rhs.pos;
	}
};
vector<event>e;
set<int>s;
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)f[fx]=fy;
	else cout<<"NO\n",exit(0);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i],f[i]=ord[l[i]]=ord[r[i]]=i;
		e.push_back({l[i],i,1});
		e.push_back({r[i],i,-1});
	}
	sort(e.begin(),e.end());
	for(int i=0;i<e.size();i++){
		int t=e[i].id;
		if(~e[i].op){
			for(auto j:s)
				if(j<=r[t])merge(t,ord[j]);
				else break;
			s.insert(r[t]);
		}else s.erase(r[t]);
	}
	for(int i=2;i<=n;i++)
		if(find(i)!=find(1))
			cout<<"NO\n",exit(0);
	cout<<"YES\n";
}