#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,k;
int w[N],cnt[N],p[N];
vector<int> sn[N];

pair<int,int> dfs(int k,int K){
	if(cnt[k]==0){
		return {w[k],K*w[k]};
	}
	int kk=K/cnt[k],rs=K%cnt[k];
	vector<int> ws;
	int sum=K*w[k],dl=w[k];
	for(auto x:sn[k]){
		auto nw=dfs(x,kk);
		sum+=nw.second;
		ws.push_back(nw.first);
	} 
	sort(ws.begin(),ws.end());
	reverse(ws.begin(),ws.end());
	for(int i=0;i<rs;i++)sum+=ws[i];
	dl+=ws[rs];
	return {dl,sum};
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cnt[i]=0;
		sn[i].clear();
	}
	for(int i=2;i<=n;i++){
		cin>>p[i];
		cnt[p[i]]++;
		sn[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)cin>>w[i];
	cout<<dfs(1,k).second<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}