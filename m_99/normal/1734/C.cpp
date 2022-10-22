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
		
		int n;
		cin>>n;
		string s;
		cin>>s;
		
		string t(n,'1');
		long long ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j+=i){
				if(t[j-1]=='1'){
					if(s[j-1]=='1')break;
					t[j-1] = '0';
					ans += i;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}