#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n;
	cin>>n;
	
	set<int> S;
	
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		S.insert(a);
	}
	
	int ans = 0;
	
	while(S.size()!=0){
		int K = *S.begin();
		ans ++;
		auto it = S.begin();
		while(it!=S.end()){
			if(*it%K==0){
				it = S.erase(it);
			}
			else{
				it++;
			}
		}
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}