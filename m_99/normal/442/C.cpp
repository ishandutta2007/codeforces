#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	map<int,int> mp;
	set<pair<int,int>> S;
	for(int i=0;i<n;i++){
		mp[i] = a[i];
		S.insert(make_pair(a[i],i));
	}
	
	long long ans = 0LL;
	long long offset = 0LL;
	
	while(true){
		if(mp.size()<=2)break;
		int ind = (*S.begin()).second;

		S.erase(S.begin());
		auto it = mp.lower_bound(ind);
		long long x,y;
		if(it==mp.begin())x = -1;
		else{
			it--;
			x = a[it->first];
			it++;
		}
		it++;
		if(it==mp.end()){
			y = -1;
		}
		else{
			y = a[it->first];
		}
		it--;
		if(x==-1||y==-1){
			ans += (mp.size()-2) * (it->second-offset);
			offset = it->second;
		}
		else{
			ans += min(x,y)-offset;
		}
		
		
		mp.erase(it);
	}
	
	cout<<ans<<endl;
	
	
	
    return 0;
}