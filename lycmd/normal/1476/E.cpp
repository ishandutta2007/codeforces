#include<bits/stdc++.h>
using namespace std;
int const N=100010,M=1100010;
int n,m,k,b[N],a[M],deg[M],vis[M];
vector<int>ans,e[M];
string s[N];
queue<int>q;
int ord(const string&s){
	int res=0;
	for(char c:s)
		res=res<<5|(c!='_'?c-96:30);
	return res;
}
int pat(const string&a,const string&b){
	for(int i=0;i<k;i++)
		if(a[i]!='_'&&a[i]!=b[i])
			return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>s[i],a[b[i]=ord(s[i])]=i;
	while(m--){
		string t;int x;cin>>t>>x;
		if(!pat(s[x],t))
			cout<<"NO\n",exit(0);
		vector<int>p;
		for(int i=0;i<1<<k;i++){
			string t1=t;
			for(int j=0;j<k;j++)
				if(i>>j&1)t1[j]='_';
			int o=a[ord(t1)];
			if(o&&o!=x)
				e[x].push_back(o),deg[o]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(!deg[i])
			q.push(i),vis[i]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		ans.push_back(x);
		for(int y:e[x])
			if(!vis[y]&&!--deg[y])
				q.push(y),vis[y]=1;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			cout<<"NO\n",exit(0);
	cout<<"YES\n";
	for(int x:ans)cout<<x<<" ";
	cout<<"\n";
}