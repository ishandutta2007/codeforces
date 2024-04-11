#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
 
 
int main(){
	
	int _t;
	cin>>_t;
//	_t = 1;
	rep(_,_t){
		
		int n,a;
		scanf("%d",&n);
		vector<int> cnt(n+1,0);
		rep(i,n){
			scanf("%d",&a);
			cnt[a]++;
		}
		vector<int> ncnt(n+1,0);
		rep(i,n+1){
			ncnt[cnt[i]]++;
		}
		int ans = 0;
		for(int i=n;i>=1;i--){
			if(ncnt[i]>0)ans+= i;
			if(ncnt[i]>1){
				ncnt[i-1]+=ncnt[i]-1;
			}
		}
		printf("%d\n",ans);
		
	}
	
	return 0;
}