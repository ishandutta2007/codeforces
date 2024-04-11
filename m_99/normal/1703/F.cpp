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
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
			a[i]--;
		}
		vector<int> S(n,0);
		rep(i,n){
			if(a[i] < i){
				S[i]++;
			}
			if(i!=0)S[i] += S[i-1];
		}
		long long ans= 0;
		rep(i,n){
			if(a[i]<i&&a[i]>0){
				ans += S[a[i]-1];
				//cout<<i<<','<<S[a[i]-1]<<endl;
			}
		}
		cout<<ans<<endl;
	}
	
    return 0;
}