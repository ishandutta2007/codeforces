#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		cin>>n;
		string s;
		cin>>s;
		
		int nn = s.size();
		if(s==string(nn,'D')||s==string(nn,'R')){
			cout<<n<<endl;
			continue;
		}
		vector<int> x(1,0),y(1,0);
		rep(i,nn){
			x.push_back(x.back());
			y.push_back(y.back());
			if(s[i]=='D')x.back()++;
			else y.back()++;
		}
		long long ans = 0LL;
		rep(i,nn){
			if(s[i]!=s[i+1]){
				long long w = n-1 - x[i+1] + 1;
				long long h = n-1 - y[i+1] + 1;
				ans += w*h;
				//cout<<w<<','<<h<<endl;
				w = 0,h = 0;
				w = x.back() - x[i+1] + 1;
				h = y.back() - y[i+1] + 1;
				//cout<<w<<','<<h<<endl;
				ans -= w*h;
				for(int j=i;j<x.size();j++)ans++;
				break;
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}