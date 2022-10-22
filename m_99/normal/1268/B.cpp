#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

	

int main(){
	
	int n;
	cin>>n;
	
	vector<long long> a(n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	long long A1 = 0,A2 = 0;
	
	for(int i=0;i<n;i++){
		if(i%2==0){
			A1 += a[i]/2;
			A2 += (a[i]+1)/2;
		}
		else{
			A1 += (a[i]+1)/2;
			A2 += a[i]/2;
		}
	}
	
	cout<<min(A1,A2)<<endl;
	
	
	return 0;
}