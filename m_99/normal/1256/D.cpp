#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long n,k;
		scanf("%lld %lld",&n,&k);
		
		string s;
		cin>>s;
		//cout<<'a'<<endl;
		vector<int> pos;
		rep(i,s.size()){
			if(s[i]=='0')pos.push_back(i);
		}
		//cout<<'a'<<endl;
		rep(i,pos.size()){
			long long t = abs(pos[i]-i);
			if(k>=t){
				k -= t;
				pos[i] = i;
			}
			else{
				while(k!=0){
					pos[i]--;
					k--;
				}
			}		
		}
	//	cout<<'a'<<endl;
		string ans(n,'1');
		rep(i,pos.size())ans[pos[i]] = '0';
		
		cout<<ans<<endl;
	}
	
	return 0;
}