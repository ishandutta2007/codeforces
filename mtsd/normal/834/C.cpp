#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;

long long gcd(long long  v,long long b){
	if(v>b) return gcd(b,v);
	if(v==b) return b;
	if(b%v==0) return v;
	return gcd(v,b%v);
}

int main(){
	set<long long>st;
	for(long long i=1;i<=1000000;i++){
		st.insert(i*i*i);
	}
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		long long a,b;
		scanf("%lld",&a);
		scanf("%lld",&b);
		long long c;
		if(st.count(a*b)==1){
			c = gcd(a,b);
			if(c%(a/c)==0&&c%(b/c)==0){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}else{
			printf("No\n");
		}
	}
	return 0;
}