#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n;
		cin>>n;
		vector<int> a(n);
		int sum = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum ^= a[i];
		}
		
		int maxi = -1;
		for(int i=0;i<30;i++){
			if((sum>>i)&1)maxi=i;
		}
		
		if(maxi==-1){
			printf("DRAW\n");
			continue;
		}
		
		int c0 = 0,c1 = 0;
		for(int i=0;i<n;i++){
			if((a[i]>>maxi)&1)c1++;
			else c0++;
		}
		
		if(c1%4==1){
			printf("WIN\n");
			continue;
		}
		else{
			if(c0%2==1)printf("WIN\n");
			else printf("LOSE\n");
		}
		
	}
	
	return 0;
}