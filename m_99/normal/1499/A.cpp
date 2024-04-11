#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000


int main(){
	
	
	int t;
	cin>>t;
	
	rep(_,t){
		
		int n,k1,k2,w,b;
		scanf("%d %d %d %d %d",&n,&k1,&k2,&w,&b);
		
		
		int W = (k1+k2)/2;
		int B = (n*2 - (k1+k2))/2;
		
		if(w<=W&&b<=B)printf("YES\n");
		else printf("NO\n");
	}
		
	
    return 0;
}