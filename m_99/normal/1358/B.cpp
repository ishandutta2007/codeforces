#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001



int main(){
	
	int t;
	cin>>t;
	
	
	for(int _=0;_<t;_++){
		int n;
		scanf("%d",&n);
		
		vector<int> a(n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		
		sort(a.begin(),a.end());
		
		while(a.size()!=0){
			if(a.back() >= 1 + a.size()){
				a.pop_back();
			}
			else{
				break;
			}
		}
		printf("%d\n",a.size()+1);
	}
	
	return 0;	
}