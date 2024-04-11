#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

bool exists[1<<21];

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		string s;
		cin>>s;
		
		int maxi = 0;
		
		rep(i,100){
			if((1<<i)>n){
				maxi = i;
				break;
			}
		}

		maxi = min(maxi,k);
		
		string ans(k-maxi,'0');
		
		rep(i,1+(1<<maxi))exists[i] = false;
		
		vector<int> sum(n+1,0);
		rep(i,n){
			if(s[i]=='0')sum[i+1] = 1;
			sum[i+1] += sum[i];
		}
		
		rep(i,n-k+1){
			int B = i + k - 1;
			int t = 0;
			if(sum[i+(k-maxi)] - sum[i] != 0)continue;
			rep(j,maxi){
				t <<= 1;
				int temp = s[B - (maxi-1) + j] - '0';
				temp ^= 1;
				t += temp;
			}
			exists[t] = true;
		}
		
		int t = 0;
		rep(i,n+5){
			if(!exists[i]){
				t = i;
				break;
			}
		}
		
		string y = "";
		rep(i,maxi){
			y += '0' + (t&1);
			t >>= 1;
		}
		reverse(y.begin(),y.end());
		ans += y;
		
		
		if(t==0){
			printf("YES\n");
			cout<<ans<<endl;
		}
		else{
			printf("NO\n");
		}
		//cout<<ans<<endl;
		
	}
	
    return 0;
}