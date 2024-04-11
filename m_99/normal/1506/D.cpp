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
		map<int,int> mp;
		rep(i,n){
			int a;
			scanf("%d",&a);
			mp[a]++;
		}
		
		int maxi = 0;
		for(auto a:mp){
			maxi = max(maxi,a.second);
		}
		
		int remain = n-maxi;
		while(remain!=0&&maxi!=0){
			remain--;
			maxi--;
		}
		
		if(maxi==0&&remain%2==1)maxi = 1;
		
		printf("%d\n",maxi);
		
		
	}

    return 0;
}