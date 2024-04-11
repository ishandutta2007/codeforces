#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int t,n,m;
string res;
struct dsu{
	int n,cur,f[N];
	void init(int tn){
		n=cur=tn;
		for(int i=1;i<=n;i++)
			f[i]=i;
	}
	int find(int x){
		return x^f[x]?f[x]=find(f[x]):x;
	}
	int merge(int x,int y){
		int fx=find(x),fy=find(y);
		return fx^fy?(f[fx]=fy,cur--,1):0;
	}
};
dsu r,b;
vector<array<int,3> >e,et,tr;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		e.clear(),et.clear(),tr.clear();
		cin>>n>>m,e.resize(m);
		for(int i=0;i<m;i++)
			cin>>e[i][0]>>e[i][1],e[i][2]=i;
		r.init(n);
		for(auto[x,y,id]:e)
			(!r.merge(x,y)?et:tr).push_back({x,y,id});
		int ans=2*n;
		for(int i=0;i<1<<et.size();i++){
			string t(m,48);
			r.init(n),b.init(n);
			for(int j=0;j<et.size();j++)
				(i>>j&1?r:(t[et[j][2]]++,b)).merge(et[j][0],et[j][1]);
			for(auto[x,y,id]:tr)
				if(!r.merge(x,y))
					b.merge(x,y),t[id]++;
			if(ans>r.cur+b.cur)
				ans=r.cur+b.cur,res=t;
		}
		cout<<res<<"\n";
	}
	return 0;
}