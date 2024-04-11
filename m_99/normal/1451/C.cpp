#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

	

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int n,k;
		scanf("%d %d",&n,&k);
		string a,b;
		cin>>a>>b;
		
		vector<int> cnt(26,0),cnt2(26,0);
		
		rep(i,n){
			cnt[a[i]-'a']++;
			cnt2[b[i]-'a']++;
		}
		
		rep(i,25){
			while(cnt[i]>cnt2[i]){
				cnt[i]-=k;
				cnt[i+1]+=k;
			}
		}
		
		if(cnt==cnt2)printf("YES\n");
		else printf("NO\n");
		
	}
	
    return 0;
}