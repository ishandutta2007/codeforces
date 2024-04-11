#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

vector<int> get(int n,long long k){
	
	vector<int> ret;
	int last = 0;
	while(last!=n){
		for(int i=last;i<n;i++){
			if(i==n-1){
				for(int j=n-1;j>=last;j--){
					ret.push_back(j);
				}
				return ret;
			}
			if(k >= (1LL<<(n-i-2))){
				k -= (1LL<<(n-i-2));
			}
			else{
				for(int j=i;j>=last;j--){
					ret.push_back(j);
				}
				last = i+1;
			}
		}
	}
	return ret;
	
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		long long k;
		scanf("%d %lld",&n,&k);
		
		
		if(n<=61){
			if((1LL<<(n-1))<k){
				printf("-1\n");
				continue;
			}
		}
		
	
		k--;
		vector<int> ret = get(min(n,61),k);
		vector<int> ans;
		rep(i,n-(min(n,61))){
			ans.push_back(i);
		}
		int last = 0;
		if(ans.size()>0){
			last = ans.back()+1;
		}
		rep(i,ret.size()){
			ans.push_back(ret[i]+last);
		}
		
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%d",ans[i]+1);
		}
		printf("\n");
	}
	
	
    return 0;
}