#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 2000000001

long long get(vector<pair<long long,char>> x){
	vector<long long> B,R;
	B.push_back(x[0].first);
	R.push_back(x[0].first);
	rep(i,x.size()){
		if(x[i].second=='B'){
			B.push_back(x[i].first);
		}
		if(x[i].second=='R'){
			R.push_back(x[i].first);
		}
	}
	
	B.push_back(x.back().first);
	R.push_back(x.back().first);
	
	long long ret = x.back().first - x[0].first;

	long long Ret = ret*2;
	ret *= 3;
	
	long long maxi0 = 0LL,maxi1=0LL;
	rep(i,B.size()-1){
		maxi0 = max(maxi0,B[i+1]-B[i]);
	}
	rep(i,R.size()-1){
		maxi1 = max(maxi1,R[i+1]-R[i]);
	}
	
	return min(Ret,ret-maxi0-maxi1);
}

int main(){	

	int n;
	cin>>n;
	
	deque<pair<long long,char>> x(n);
	bool f = false;
	rep(i,n){
		scanf("%lld %c",&x[i].first,&x[i].second);
		if(x[i].second=='P'){
			f  =true;
		}
		
	}

	
	if(f){
		long long ans = 0LL;
		bool B = false,R = false;
		while(true){
			if(x.front().second=='P'){
				if(B)ans += x.front().first;
				if(R)ans += x.front().first;
				break;
			}
			else if(x.front().second=='B'){
				if(!B){
					B=true;
					ans -= x.front().first;
				}
			}
			else{
				if(!R){
					R = true;
					ans -= x.front().first;
				}
			}
			x.pop_front();
		}
		
		B = false,R = false;
		while(true){
			if(x.back().second=='P'){
				if(B)ans -= x.back().first;
				if(R)ans -= x.back().first;
				break;
			}
			else if(x.back().second=='B'){
				if(!B){
					B=true;
					ans += x.back().first;
				}
			}
			else{
				if(!R){
					R = true;
					ans += x.back().first;
				}
			}
			x.pop_back();
		}
		
		while(x.size()!=1){
			vector<pair<long long,char>> V;
			V.push_back(x.front());
			x.pop_front();
			while(true){
				V.push_back(x.front());
				if(x.front().second=='P')break;
				x.pop_front();
			}
			ans += get(V);
		}
		cout<<ans<<endl;
	}
	else{
		long long mB = Inf,MB = -Inf,mR = Inf,MR = -Inf;
		
		rep(i,n){
			if(x[i].second=='B'){
				mB = min(mB,x[i].first);
				MB = max(MB,x[i].first);
			}
			else{
				mR = min(mR,x[i].first);
				MR = max(MR,x[i].first);
			}
		}
		
		cout<<max(0LL,MB-mB)+max(0LL,MR-mR)<<endl;
	}
	
    return 0;
}