#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> ans;
		vector<int> w(n,0);
		rep(i,n){
			for(int j=i+1;j<n;j++){
				if(n%2==0){
					if(j-i==n/2){
						ans.push_back(0);
						continue;
					}
				}
				if((j-i)<=n/2){
					ans.push_back(1);
					w[i]++;
					w[j]--;
				}
				else{
					ans.push_back(-1);
					w[j]++;
					w[i]--;
				}
			}
		}
		/*
		rep(i,n)cout<<w[i]<<',';
		cout<<endl;
		*/
		
		
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		cout<<endl;
		
	}
		
    return 0;
}