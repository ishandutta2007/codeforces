#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300



int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int n;
		scanf("%d",&n);
		
		vector<long long> a(n);
		long long sum = 0LL;
		rep(i,n){
			scanf("%lld",&a[i]);
			sum += a[i];
		}
		
		if(sum%n!=0){
			printf("-1\n");
			continue;
		}
		vector<long long> I,J,X;
		sum /= n;
		for(int i=1;i<n;i++){
			long long x = ((i+1) - ((a[i]%(i+1))))%(i+1);
			I.push_back(1);
			J.push_back(i+1);
			X.push_back(x);
			a[i] += x;
			a[0] -= x;
			
			x = a[i]/(i+1);
			I.push_back(i+1);
			J.push_back(1);
			X.push_back(x);
			a[i] -= x*(i+1);
			a[0] += x*(i+1);
			
		}
		
		
		for(int i=1;i<n;i++){
			if(sum>a[i]){
				I.push_back(1);
				J.push_back(i+1);
				X.push_back(sum-a[i]);
				a[0] -= sum-a[i];
				a[i] = sum;
			}
		}
		
		printf("%d\n",(int)I.size());
		rep(i,I.size()){
			printf("%lld %lld %lld\n",I[i],J[i],X[i]);
		}
		
	}
	
    return 0;
}