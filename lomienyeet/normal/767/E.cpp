#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,r,s=0;
	cin>>n>>r;
	int c[n],w[n],ans[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
		ans[i]=c[i]/100;
	}
	for(int i=0;i<n;i++)cin>>w[i];
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	for(int i=0;i<n;i++){
		if(!(c[i]%100))continue; // alr ok
		pq.push({w[i]*(100-c[i]%100),i}); // cost
		r-=c[i]%100;
		if(r<0){ // ohno!!!!!!!!!!!!!!
			r+=100;
			s+=pq.top().first;
			ans[pq.top().second]++; // omg change !!!!!!!!!!
			pq.pop();
		}
	}
	cout<<s<<"\n";
	for(int i=0;i<n;i++)cout<<ans[i]<<" "<<max(0ll,c[i]-ans[i]*100)<<"\n";
}