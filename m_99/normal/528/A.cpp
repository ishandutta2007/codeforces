#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int w,h;
	scanf("%d %d",&w,&h);
	set<long long> W,H;
	W.insert(0);
	W.insert(w);
	H.insert(0);
	H.insert(h);
	multiset<long long> Ws,Hs;
	Ws.insert(w);
	Hs.insert(h);
	
	int n;
	scanf("%d",&n);
	rep(_,n){
		char c;
		int X;
		cin>>c>>X;
		
		if(c=='H'){
			auto it = H.lower_bound(X);
			Hs.insert((*it) - X);
			long long t = *it;
			it--;
			t -= *it;
			Hs.insert(X-(*it));
			auto it2 = Hs.lower_bound(t);
			Hs.erase(it2);
			H.insert(X);
		}
		else{
			auto it = W.lower_bound(X);
			Ws.insert((*it) - X);
			long long t = *it;
			it--;
			t -= *it;
			Ws.insert(X-(*it));
			auto it2 = Ws.lower_bound(t);
			Ws.erase(it2);
			W.insert(X);
			
		}
		
		long long ans;
		auto it = Ws.end();
		it--;
		ans = *it;
		it = Hs.end();
		it--;
		ans *= *it;
		
		printf("%lld\n",ans);
	}
	
	return 0;
}