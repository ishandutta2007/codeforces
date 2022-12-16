#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
map<int,priority_queue<int,vector<int>,greater<int> > > mp;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		for(int j=2;j*j<=a;j++){
			if(a%j==0){
				int x=0;
				while(a%j==0){
					a/=j;
					x++;
				}
				// cerr<<" "<<j<<" "<<x<<endl;
				mp[j].push(x);
			}
		}
		if(a!=1){
			// cerr<<" "<<a<<" "<<1<<endl;
			mp[a].push(1);
		}
	}
	LL ans=1;
	for(auto pq:mp){
		if((int)pq.second.size()<n){
			pq.second.push(0);
		}
		if((int)pq.second.size()==n){
			pq.second.pop();
			int x=pq.second.top();
			// cerr<<pq.first<<" "<<pq.second.top()<<endl;
			while(x--){
				ans*=pq.first;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}