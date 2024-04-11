#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		cin>>n;
		vector<int> t;
		int m = 0;
		while(n!=0){
			m = max((long long)m,n%3);
			t.push_back(n%3);
			n/=3;
		}
		reverse(t.begin(),t.end());
		
		if(m==2){
			t.insert(t.begin(),0);
			int maxi = 0;
			rep(i,t.size()){
				if(t[i]==0)maxi = i;
				if(t[i]==2)break;
			}
			t[maxi] ++;
			for(int i=maxi+1;i<t.size();i++)t[i] = 0;
		}
		reverse(t.begin(),t.end());
		
		long long ans = 0;
		n = 1;
		rep(i,t.size()){
			ans += n * t[i];
			n *= 3;
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}