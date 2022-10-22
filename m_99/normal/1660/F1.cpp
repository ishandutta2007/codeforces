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
		scanf("%d",&n);
		string s;
		cin>>s;
		int ans = 0;
		rep(i,n){
			int p = 0,m = 0;
			int cur = 0;
			for(int j=i;j<n;j++){
				if(s[j]=='+'){
					p++;
					if(cur%2==1)cur--;
				}
				else{
					m++;
					cur++;
				}
				if(m>=p && (m-p)%3==0){
					int cc = cur;
					if(cc%2==1)cc--;
					if(m-cc <= p+cc/2)ans++;
					
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}