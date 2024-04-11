#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
int a[N];
int f[N];
int cnt[N];
int fc[N];
int ccnt[N];
int mx[N];
vector<int> fcnts[N];
int main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>f[i];
			cnt[i]=0;
			ccnt[i]=0;
			mx[i]=0;
			fc[i]=0;
			fcnts[i].clear();
		}
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		for(int i=1;i<=n;i++)fc[a[i]]+=f[i];
		for(int i=1;i<=n;i++)ccnt[cnt[i]]++;
		for(int i=1;i<=n;i++)fcnts[cnt[i]].push_back(fc[i]);
		for(int i=1;i<=n;i++)sort(fcnts[i].begin(),fcnts[i].end());
		for(int i=1;i<=n;i++){
			mx[cnt[i]]=max(mx[cnt[i]],i);
		}
		int cur=n;
		LL ans=0;
		LL fans=0;
		static priority_queue<int> q;
		while(!q.empty())q.pop();
		for(int i=n;i>=1;i--){
			for(int j=0;j<ccnt[i];j++)q.push(fcnts[i][j]);
			if(q.empty())continue;
			ans+=i;
			fans+=min(i,q.top());
			q.pop();
		}
		cout<<ans<<" "<<fans<<endl;
	}
	return 0;
}