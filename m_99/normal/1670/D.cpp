#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

long long get(long long n,int a,int b,int c){
	long long ok = Inf,ng = -1;
	while(ok-ng>1){
		long long mid = (ok+ng)/2;
		long long A = mid+a,B = mid+b,C = mid+c;
		if(2 * (A*B + B*C + C*A) >= n)ok = mid;
		else ng = mid;
	}
	return 3*ok + a+b+c;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		long long ans = Inf;
		
		ans = min(ans,get(n,0,0,0));
		ans = min(ans,get(n,0,0,1));
		ans = min(ans,get(n,0,1,1));
		
		cout<<ans<<endl;
	}
	
    return 0;
}