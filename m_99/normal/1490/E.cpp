#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<pair<int,int>> a(n);
		rep(i,n){
			scanf("%d",&a[i].first);
			a[i].second = i;
		}
		sort(a.begin(),a.end());
		
		int ok = n,ng = -1;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			
			long long cur = 0LL;
			rep(i,n){
				if(i<=mid)cur += a[i].first;
				else{
					if(cur >= a[i].first)cur += a[i].first;
					else{
						cur = -1;
						break;
					}
				}
			}
			if(cur!=-1)ok = mid;
			else ng = mid;
		}
		
		vector<int> ans;
		for(int i=ok;i<n;i++)ans.push_back(a[i].second);
		sort(ans.begin(),ans.end());
		printf("%d\n",ans.size());
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%d",ans[i]+1);
		}
		printf("\n");
		
				
		
	}
	
    return 0;
}