#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N];

void solve(){
	cin>>n;
	int s=0;
	vector<int> pos;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		if(a[i])pos.push_back(i);
	}
	if(s&1){
		cout<<-1<<endl;
		return ;
	} 
	if(s==0){
		cout<<n<<endl;
		for(int i=1;i<=n;i++){
			cout<<i<<' '<<i<<'\n'; 
		}
		return ;
	}
	vector<pair<int,int>> res;
	if(pos[0]>1)res.push_back({1,pos[0]-1}); 
	pos.push_back(n+1); 
	for(int i=0;i+1<pos.size();i+=2){
		int fl=(pos[i+1]-pos[i])&1;
		if(a[pos[i]]==a[pos[i+1]]){
			if(fl)res.push_back({pos[i],pos[i+2]-1});
			else{
				res.push_back({pos[i],pos[i]});
				res.push_back({pos[i]+1,pos[i+2]-1});
			}
		}else{
			if(fl){
				res.push_back({pos[i],pos[i]});
				res.push_back({pos[i]+1,pos[i+2]-1});
			}else res.push_back({pos[i],pos[i+2]-1});
		}
	}
	cout<<res.size()<<endl;
	for(auto x:res)cout<<x.first<<' '<<x.second<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}