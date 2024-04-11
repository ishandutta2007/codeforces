#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000


int main(){
	
	int n,m;
	cin>>n>>m;
	
	string s;
	cin>>s;
	
	vector S(3,vector(3,vector<int>(n+1,0)));
	
	rep(i,n){
		S[i%3][s[i]-'a'][i+1]++;
	}
	
	rep(i,3){
		rep(k,3){
			rep(j,n){
				S[i][k][j+1] += S[i][k][j];
			}
		}
	}
	
	rep(_,m){
		int l,r;
		scanf("%d %d",&l,&r);
		
		int maxi = 0;
		vector<int> t = {0,1,2};
		do{
			int sum = 0;
			rep(i,3){
				sum += S[i][t[i]][r] - S[i][t[i]][l-1];
			}
			maxi = max(maxi,sum);
		}
		while(next_permutation(t.begin(),t.end()));
		
		maxi = (r-l+1) - maxi;
		
		printf("%lld\n",maxi);
	}
	
	return 0;
}