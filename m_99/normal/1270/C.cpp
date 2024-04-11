#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		
		long long sum = 0;
		vector<long long> a(n);
		for(int j=0;j<n;j++){
			cin>>a[j];
			sum += (long long)a[j];
		}
		
		long long s1 = 0;
		if(sum%2==1)s1 ++;
		s1 += ((long long)1<<50);
		
		sum += s1;
		long long xorsum = s1;
		for(int j=0;j<n;j++)xorsum ^= a[j];
		xorsum*=2;
		long long s2 = (xorsum-sum)/2;
		
		cout<<3<<endl;
		cout<<s1<<' '<<s2<<' '<<s2<<endl;
		

		
	}
	
    return 0;
}