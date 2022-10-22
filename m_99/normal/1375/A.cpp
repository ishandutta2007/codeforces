#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		
		for(int i=0;i<n;i++){
			if(i%2==0){
				if(a[i]>0)a[i]*=-1;
			}
			else{
				if(a[i]<0)a[i]*=-1;
			}
		}
		
		for(int i=0;i<n;i++){
			if(i!=0)printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
	}
		
	return 0;
}