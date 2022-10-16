#include<bits/stdc++.h>
#define int long long
const int N=1005;
using namespace std;

string s[N],t;

void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];cin>>t;
	for(int i=0;i<m;i++)t[i]-='0'-1;
	vector<int> f(m+1);
	vector<pair<int,int>>v(2005);f[0]=1;
	vector<vector<int>>pr(m+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			s[i][j]-='0'-1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m-1;j++)
			v[s[i][j]*11+s[i][j+1]]={i,j+1};
		for(int j=0;j<m-2;j++)
			v[s[i][j]*121+s[i][j+1]*11+s[i][j+2]]={i,j+2};
	}
	for(int i=0;i<m;i++){
		if(!f[i])continue;
		if(i+1<m)
			if(v[t[i]*11+t[i+1]].first)
				f[i+2]|=f[i],pr[i+2]={2,v[t[i]*11+t[i+1]].first,v[t[i]*11+t[i+1]].second};
		if(i+2<m)
			if(v[t[i]*121+t[i+1]*11+t[i+2]].first)
				f[i+3]|=f[i],pr[i+3]={3,v[t[i]*121+t[i+1]*11+t[i+2]].first,v[t[i]*121+t[i+1]*11+t[i+2]].second};
	}
	if(!f[m])cout<<-1<<endl;
	else{
		stack<vector<int>> ans;
		while(m){
			ans.push({pr[m][2]-pr[m][0]+2,pr[m][2]+1,pr[m][1]});
			m=m-pr[m][0];
		}
		cout<<ans.size()<<endl;
		while(ans.size()){
			for(auto x:ans.top())cout<<x<<' ';
			cout<<endl;ans.pop();
		}
	}
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}