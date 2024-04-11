//copy from huangxiaohua, just for testing

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,st,ed,a[200500],cl[200500],cr[200500],f[200500];
queue<int> q;

struct SB{
	#define md ((l+r)/2)
	#define ls (id*2)
	#define rs (ls+1)
	
	set<int> s[800500];
	
	void build(int id,int l,int r){
		s[id].clear();
		if(l==r)return;
		build(ls,l,md);build(rs,md+1,r);
	}
	
	void add(int id,int l,int r,int x,int y,int w){
		if(x<=l&&r<=y){
			s[id].insert(w);return;
		}
		if(x<=md)add(ls,l,md,x,y,w);
		if(y>md)add(rs,md+1,r,x,y,w);
	}
	
	void add2(int id,int l,int r,int w){
		if(w>=l&&w<=r){
			while(1){
				auto it=s[id].lower_bound(cl[w]);
				if(it==s[id].end()||(*it)>cr[w])break;
				int t=(*it);s[id].erase(it);
				if(t!=st&&!f[t]){
					f[t]=f[w]+1;
					q.push(t);
				}
			}
		}
		if(l==r)return;
		if(w<=md)add2(ls,l,md,w);
		else add2(rs,md+1,r,w);
	}
}sb;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>st>>ed;
		for(i=1;i<=n;i++){
			cin>>a[i];
			cl[i]=max(1,i-a[i]);
			cr[i]=min(n,i+a[i]);
			f[i]=0;
		}
		sb.build(1,1,n);
		
		for(i=1;i<=n;i++){
			sb.add(1,1,n,cl[i],cr[i],i);
		}
		
		while(!q.empty())q.pop();
		q.push(st);
		
		while(!q.empty()){
			k=q.front();q.pop();
			if(k==ed){
				cout<<f[k]<<'\n';
				break;
			}
			sb.add2(1,1,n,k);
		}
	}
}