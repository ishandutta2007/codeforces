#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

	

int main(){
	
	int n,k;
	cin>>n>>k;
	
	string S;
	cin>>S;
	
	string T;
	T = S;
	vector<char> mini(k,'{');
	for(int i=0;i<k;i++){
		for(int j=i;j<T.size();j+=k){
			T[j] = T[i];
			mini[k] = min(mini[k],S[j]);
		}
	}
	
	if(S>T){
		for(int i=k-1;i>=0;i--){
			if(T[i]=='9'){
				for(int j=i;j<T.size();j+=k){
					T[j]='0';
				}
				continue;
			}
			else{
				for(int j=i;j<T.size();j+=k){
					T[j]++;
				}
				break;
			}
		}
	}
	
	
	cout<<T.size()<<endl;
	cout<<T<<endl;
	
	
	return 0;
}