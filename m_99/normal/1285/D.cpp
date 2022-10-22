#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){

	int n;
	cin>>n;
	
	vector<int> a(n);
	
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	int ans = 0;
	vector<vector<int>> L;
	L.push_back(a);
	
	for(int i=30;i>=0;i--){
		bool f = true;
		for(int j=0;j<L.size();j++){
			f = true;
			for(int k=1;k<L[j].size();k++){
				if((L[j][k]&(1<<i))!=(L[j][k-1]&(1<<i))){
					f=false;
					break;
				}
			}
			if(f)break;
		}
		
		vector<vector<int>> NL;
		
		if(!f){
			ans |= (1<<i);
			for(int j=0;j<L.size();j++){
				vector<int> L1,L2;
				for(int k=0;k<L[j].size();k++){
					if(L[j][k]&(1<<i))L1.push_back(L[j][k]);
					else L2.push_back(L[j][k]);
				}
				NL.push_back(L1);
				NL.push_back(L2);
			}
		}
		else{
			for(int j=0;j<L.size();j++){
				f = true;
				for(int k=1;k<L[j].size();k++){
					if((L[j][k]&(1<<i))!=(L[j][k-1]&(1<<i))){
						f=false;
						break;
					}
				}
				if(!f)continue;
				else{
					NL.push_back(L[j]);
				}
			}
		}
		swap(L,NL);
	}
	
	cout<<ans<<endl;
	
	return 0;
}