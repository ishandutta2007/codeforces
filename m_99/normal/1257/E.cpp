#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001



int main(){
	
	int k1,k2,k3;
	cin>>k1>>k2>>k3;
	
	set<int> S1,S2,S3;
	
	for(int i=0;i<k1;i++){
		int a;
		cin>>a;
		S1.insert(a);
	}
	
	for(int i=0;i<k2;i++){
		int a;
		cin>>a;
		S2.insert(a);
	}
	
	for(int i=0;i<k3;i++){
		int a;
		cin>>a;
		S3.insert(a);
	}
	
	vector<int> v1(k1+k2+k3+2,0);
	vector<int> v3 = v1;
	
	for(int i=1;i<v1.size();i++){
		v1[i] = v1[i-1];
		if(!S1.count(i)){
			v1[i]++;
			if(S2.count(i))v1[i]++;
		}
		v1[i] --;
	}
	v3.back() = v3.size()-1;
	for(int i=v3.size()-2;i>=0;i--){
		v3[i] = v3[i+1];
		if(!S3.count(i)){
			v3[i]++;
			if(S2.count(i))v3[i]++;
		}
		v3[i]--;
	}
	
	for(int i=1;i<v1.size();i++){
		v1[i] = min(v1[i],v1[i-1]);
	}
	
	for(int i=v3.size()-2;i>=0;i--){
		v3[i] = min(v3[i],v3[i+1]);
	}
	
	int ans = Inf;
	
	for(int i=0;i<v1.size()-1;i++){
		ans = min(ans,v1[i] + v3[i+1]);
	}
	
	cout<<ans-1-S2.size()<<endl;
	
    return 0;
}