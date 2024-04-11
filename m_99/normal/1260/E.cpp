#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000



int main(){
	
	int n;
	cin>>n;
	
	vector<long long> a(n);
	int friends;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==-1)friends=i+1;
	}
	
	int cnt = n-friends;
	
	int matches = 0;
	int nn = n;
	while(nn!=1){
		matches++;
		nn/=2;
	}
	int m = matches;
	while(friends!=1){
		matches--;
		friends/=2;
	}
	
	vector<int> w;
	w.push_back(matches);
	int now = 0;
	while(w.size()!=n){
		for(int i=0;i<(1<<now);i++){
			w.push_back(matches-now-1);
		}
		now++;
	}
	now=m-1;
	
	priority_queue<long long,vector<long long>,greater<long long>> Q;
	int last = n;
	long long ans = 0;
	
	while(matches>0){
		last--;
		if(last>=0)Q.push(a[last]);
		matches--;
		if(Q.top()==-1)break;
		//cout<<Q.top()<<endl;
		ans += Q.top();
		Q.pop();
		for(int i=0;i<(1<<now)-1;i++){
			last--;
			if(last>=0)Q.push(a[last]);
		}
		now--;
	}
	
	cout<<ans<<endl;
	
	return 0;
	
}