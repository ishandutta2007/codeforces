#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,l,r;
		scanf("%d %d %d",&n,&l,&r);
		
		multiset<int> L,R;
		
		rep(i,n){
			int x;
			scanf("%d",&x);
			if(i<l)L.insert(x);
			else R.insert(x);
		}
		
		if(l>r){
			swap(l,r);
			swap(L,R);
		}
		
		int ans = 0;
		
		for(auto it = L.begin();it!=L.end();){
			int v = *it;
			if(R.find(v)!=R.end()){
				R.erase(R.find(v));
				it = L.erase(it);
			}
			else{
				it++;
			}
		}
		
		int P = 0;
		
		{
			map<int,int> mp;
			for(auto a:R)mp[a]++;
			
			for(auto a:mp){
				P += a.second/2;
			}
		}
		
		while(L.size()!=R.size()){
			if(P>0){
				P--;
				ans++;
			}
			else{
				ans += 2;
			}
			rep(i,2){
				R.erase(R.begin());
			}
		}
		
		ans += L.size();
		
		printf("%d\n",ans);
				
		
	}
	
    return 0;
}