#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

void change(vector<long long> &a){
	long long maxi = -Inf;
	for(int i=0;i<a.size();i++){
		maxi = max(maxi,a[i]);
	}
	
	for(int i=0;i<a.size();i++){
		a[i] = maxi-a[i];
	}
}

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n;
		scanf("%d",&n);
		long long k;
		scanf("%lld",&k);
		vector<long long> a(n);
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		
		change(a);
		k--;
		for(int i=0;i<k%2;i++)change(a);
		
		for(int i=0;i<n;i++){
			if(i!=0)printf(" ");
			printf("%lld",a[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}