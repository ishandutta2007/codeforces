#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int n;

int check(vector<string> S,int b){
	int ret = 0;
	rep(i,2*n){
		rep(j,2*n){
			int t = (i+j)&1;
			t ^= b;
			int x = S[i][j]-'0';
			ret += t^x;
		}
	}
	return ret;
}

int main(){
	
	
	cin>>n;
	
	vector<vector<string>> S(4,vector<string>(n));
	rep(i,4){
		rep(j,n)cin>>S[i][j];
	}
	
	vector<int> t = {0,1,2,3};
	
	int ans = Inf;
	
	do{
		vector<string> T(2*n);
		rep(i,n){
			T[i] += S[t[0]][i];
			T[i] += S[t[2]][i];
			T[i+n] += S[t[1]][i];
			T[i+n] += S[t[3]][i];
		}
		
		ans = min(ans,check(T,0));
		ans = min(ans,check(T,1));
		
	}
	while(next_permutation(t.begin(),t.end()));
	
	cout<<ans<<endl;
	
    return 0;
}