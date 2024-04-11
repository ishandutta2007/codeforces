#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
	//	n=5000;
		vector<long long> S(n);
		rep(i,n){
			scanf("%lld",&S[i]);
		//	S[i] = 1000000;
		}
		
		long long ans = 0LL;
		vector<long long> kita(n+1,0);
		rep(i,n){
			
			if(S[i]>n){
				
				long long x = S[i]-n;
				x = min(x,kita[i]);
				kita[i] -= x;
				S[i] -= x;
			}
			
			rep(j,kita[i]){
				if(S[i]==1){
					kita[i+1] += kita[i]-j;
					break;
				}
				if(i+S[i]<n){
					kita[i+S[i]]++;
				}
				S[i] = max(S[i]-1,1LL);
			}
			if(S[i]>n){
				ans += S[i]-n;
				S[i] = n;
			}
			
			while(S[i]!=1LL){
				if(i+S[i]<n){
					kita[i+S[i]]++;
				}
				ans++;
				S[i] = max(S[i]-1,1LL);
			}
			
		}
		
		printf("%lld\n",ans);
		
	}
		
	
    return 0;
}