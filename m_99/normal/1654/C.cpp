#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		map<long long,long long> mp;
		long long s=  0;
		rep(i,n){
			long long a;
			scanf("%lld",&a);
			mp[a]++;
			s += a;
		}
		bool f = true;
		vector<long long> t(1,s);
		while(t.size()!=0){
			if(t.size()>n){
				f = false;
				break;
			}
			long long b = t.back();
			
			t.pop_back();
			if(mp[b]>0){
				mp[b]--;
				continue;
			}
			else if(b<=1){
				f = false;
				break;
			}
			t.push_back(b/2);
			t.push_back((b+1)/2);
		}
		if(t.size()==0&&f)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}