#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	
	int n,k;
	cin>>n>>k;
	string S;
	cin>>S;
	
	set<char> s;
	for(int i=0;i<k;i++){
		char c;
		cin>>c;
		s.insert(c);
	}
	
	vector<int> V;
	bool f = false;
	for(int i=0;i<S.size();i++){
		if(s.count(S[i])==false){
			f=false;
			continue;
		}
		if(f){
			V.back()++;
		}
		else{
			V.push_back(1);
			f=true;
		}
	}
	
	long long ans = 0;
	for(int i=0;i<V.size();i++){
		ans += ((long long)V[i] * (V[i]+1))/2;
	}
	
	cout<<ans<<endl;
	
	return 0;
}