#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<string> s(n);
		rep(i,n){
			cin>>s[i];
		}
		vector<string> t = s;
		sort(t.begin(),t.end());
		long long ans = 0;
		rep(i,n){
			bool f = false;
			for(int j=1;j<=s[i].size()-1;j++){
				long long d = distance(lower_bound(t.begin(),t.end(),s[i].substr(0,j)),
				upper_bound(t.begin(),t.end(),s[i].substr(0,j)));
				d *= distance(lower_bound(t.begin(),t.end(),s[i].substr(j)),
				upper_bound(t.begin(),t.end(),s[i].substr(j)));
				if(d>0)f = true;
			}
			if(f)cout<<1;
			else cout<<0;
		}
		cout<<endl;
		//cout<<ans<<endl;
		
	}
	
    return 0;
}