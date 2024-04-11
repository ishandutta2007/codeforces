#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	long long n,k;
	cin>>n>>k;
	
	map<long long,long long> mp;
	
	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		mp[a]++;
	}
	
	while(true){
		if(mp.size()==1)break;
		auto it1 = mp.begin();
		auto it2 = mp.end();
		it2--;
		
		if((*it1).second>(*it2).second){
			long long x = (*it2).first;
			long long y = (*it2).second;
			mp.erase(it2);
			it2 = mp.end();
			it2--;
			if(k>=y*(x-(*it2).first)){
				k-=y*(x-(*it2).first);
				(*it2).second+=y;
			}
			else{
				mp[x-k/y]=1;
				k=0;
			}
		}
		else{
			long long x = (*it1).first;
			long long y = (*it1).second;
			mp.erase(it1);
			it1 = mp.begin();
			if(k>=y*((*it1).first-x)){
				k-=y*((*it1).first-x);
				(*it1).second+=y;
			}
			else{
				mp[x+k/y]=1;
				k=0;
			}
		}
		if(k==0)break;
	}
	
	auto it1 = mp.begin();
	auto it2 = mp.end();
	it2--;
	
	cout<<(*it2).first-(*it1).first<<endl;
	
    return 0;
}