#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	scanf("%d",&t);
	
	for(int _=0;_<t;_++){
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<int> a(n);
		bool f = true;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=k)f=false;
		}
		
		if(f){
			printf("yes\n");
			continue;
		}

		for(int i=0;i<n;i++){
			if(a[i]==k){
				f=true;
				break;
			}
		}
		
		if(!f){
			printf("no\n");
			continue;
		}
		f=false;
		for(int i=0;i<n-1;i++){
			if(a[i]>=k&&a[i+1]>=k){
				f=true;
				break;
			}
		}
		
		for(int i=0;i<n-2;i++){
			if(a[i]>=k&&a[i+2]>=k){
				f=true;
				break;
			}
		}
		
		if(f)printf("yes\n");
		else printf("no\n");
	}
	
	return 0;
}