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
		string s;
		cin>>s;
		vector<int> cnt(26,0);
		rep(i,n){
			cnt[s[i]-'a']++;
		}
		string ans = "";
		rep(i,k){
			char c= 'a' + (n/k);
			rep(j,n/k){
				if(cnt[j]>0){
					cnt[j]--;
				}
				else{
					c = 'a' + j;
					break;
				}
				
			}
			ans += c;
		}
		cout<<ans<<endl;
		
	}	
	
	return 0;
}