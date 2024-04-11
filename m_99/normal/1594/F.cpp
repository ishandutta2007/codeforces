#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long s,n,k;
		scanf("%lld %lld %lld",&s,&n,&k);
		
		if(k>s){
			printf("NO\n");
			continue;
		}
		
		if(k==s){
			printf("YES\n");
			continue;
		}
		
		long long m = s/(k*2);
		m *= k*2;
		s -= m;
		m /= 2;
		
		m += min(k,1LL+s);
	//	cout<<m<<endl;
		if(m >= n+1)printf("NO\n");
		else printf("YES\n");
		
	}
	
	return 0;
}