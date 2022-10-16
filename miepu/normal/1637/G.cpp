#include<bits/stdc++.h>
const int N=500005;
using namespace std;

int cnt[N],nd[N],res;
priority_queue<int> q;
vector<pair<int,int>> ans;

void ins(int k){
	q.push(k);
	cnt[k]++;
	for(int i=res;i>=k&&i;i>>=1)
		if(nd[i-k])nd[i-k]--,ins(i-k);
}

void solve(){
	ans.clear();
	int n;cin>>n;
	if(n==2){
		cout<<-1<<endl;
		return ;
	}
	res=1;
	while(res<n)res<<=1;
	for(int i=n;i>=1;i--)
		cnt[i]=1,q.push(i);
	for(int i=n+1;i<=res;i++)
		cnt[i]=0;
	while(q.size()){
		int t=q.top();q.pop();
		if(!cnt[t]||t==res)continue;
		cnt[t]--;
		if(t==0){
			cnt[res]++;
			ans.push_back({0,res});
			continue;
		} 
		int fl=0;
		for(int i=res;i>=t;i>>=1){
			int r=i-t;
			if(cnt[r]){
				cnt[r]--;
				ans.push_back({t,r});
				ins(i),ins(abs(t-r));
				fl=1;
				break;
			} 
		}
		if(!fl)nd[t]++;
	}
	cout<<ans.size()<<endl;
	for(auto x:ans)
		cout<<x.first<<' '<<x.second<<'\n';
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}