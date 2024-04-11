#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int Q;
	cin>>Q;
	
	for(int i=0;i<Q;i++){
		string S;
		cin>>S;
		
		map<char,int> mp;
		for(int j=0;j<S.size();j++){
			mp[S[j]]++;
		}
		
		string T = "";
		bool f1 = false,f2 = false;
		for(int j=0;j<min(mp['U'],mp['D']);j++){
			f1=true;
			T += 'U';
		}
		
		for(int j=0;j<min(mp['L'],mp['R']);j++){
			f2=true;
			T += 'L';
		}
		
		for(int j=0;j<min(mp['U'],mp['D']);j++){
			T += 'D';
		}
		
		for(int j=0;j<min(mp['L'],mp['R']);j++){
			T += 'R';
		}
		if(!f1&&f2){
			T = "LR";
		}
		if(f1&&!f2){
			T = "UD";
		}
		
		
		cout<<T.size()<<endl;
		cout<<T<<endl;
	}
	
	
	return 0;
}