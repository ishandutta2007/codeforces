#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		k--;
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		
		vector<pair<long long,long long>> p(1,make_pair(0,0)),s(1,make_pair(0,0));
		for(int i=k+1;i<n;i++){
			s.back().second += a[i];
			s.back().first = min(s.back().first,s.back().second);
			if(s.back().second>0){
				s.emplace_back(0,0);
			}
		}
		for(int i=k-1;i>=0;i--){
			p.back().second += a[i];
			p.back().first = min(p.back().first,p.back().second);
			if(p.back().second>0){
				p.emplace_back(0,0);
			}
		}
		reverse(p.begin(),p.end());
		reverse(s.begin(),s.end());
		long long cur = a[k];
		while(p.size()!=0&&s.size()!=0){
			long long X = p.back().first,Y = s.back().first;
			if(cur + max(X,Y) < 0)break;
			if(X>Y){
				cur += p.back().second;
				p.pop_back();
			}
			else{
				cur += s.back().second;
				s.pop_back();
			}
		}
		if(p.size()==0||s.size()==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
	
}