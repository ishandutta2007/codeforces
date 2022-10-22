#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000

int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		string s;
		cin>>s;
		int n = s.size();
		
		vector sum(2,vector<int>(n+1,0));
		
		rep(i,n){
			if(s[i]=='['||s[i]==']'){
				sum[i&1][i+1] = 1;
			}
		}
		rep(i,2){
			rep(j,n){
				sum[i][j+1] += sum[i][j];
			}
		}
		
		int q;
		scanf("%d",&q);
		rep(_,q){
			int l,r;
			scanf("%d %d",&l,&r);
			printf("%d\n",abs((sum[0][r]-sum[0][l-1]) - (sum[1][r]-sum[1][l-1])));
		}
		
	}
	
	return 0;
}