#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long x;
		cin>>x;
		bool f = false;
		for(long long i=0;i<=20;i++){
			long long t = 111*i;
			if(t > x)continue;
			if((x-t)%11==0){
				f=true;
				break;
			}
		}
		
		if(f)printf("YES\n");
		else printf("NO\n");
		
	}
	
	return 0;
}