#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

unsigned long xor128() {
	static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
	unsigned long t=(x^(x<<11));
	x=y; y=z; z=w;
	return (w=(w^(w>>19))^(t^(t>>8)));
}

int main(){
	
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	
	vector<int> x(10000001,-1),y(10000001,-1);
	
	rep(_,30000000){
		int X = xor128()%n,Y = xor128()%n;
		if(X==Y)continue;
		int sum = a[X]+a[Y];
		if(x[sum]==-1){
			x[sum] = X;
			y[sum] = Y;
		}
		else{
			if(X==x[sum]||X==y[sum]||Y==x[sum]||Y==y[sum])continue;
			cout<<"YES"<<endl;
			printf("%d %d %d %d",X+1,Y+1,x[sum]+1,y[sum]+1);
			return 0;
		}
	}
			
	cout<<"NO"<<endl;
	
	
    return 0;
}