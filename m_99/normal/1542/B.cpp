#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,a,b;
		scanf("%lld %lld %lld",&n,&a,&b);
		
		long long cur = 1LL;
		bool f = false;
		if(a!=1LL){
			while(cur<=n){
				if((n-cur)%b==0){
					f=true;
					break;
				}
				cur *= a;
			}
		}
		else{
			if((n-cur)%b==0){
				f=true;
			}
		}
		
		if(f)printf("Yes\n");
		else printf("No\n");
		
	}
	
    return 0;
}