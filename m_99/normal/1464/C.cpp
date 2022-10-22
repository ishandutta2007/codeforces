#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	int n;
	cin>>n;
	
	long long T;
	cin>>T;
	
	string s;
	cin>>s;
	
	T -= (1LL << (s.back()-'a'));
	s.pop_back();
	
	T += (1LL << (s.back()-'a'));
	s.pop_back();
	
	vector<long long> cnt(26,0);
	
	rep(i,s.size()){
		cnt[s[i]-'a']++;
		T -= (1LL<<(s[i]-'a'));
	}
	
	//T = abs(T);
//cout<<T<<endl;
	if(T%2!=0){
		cout<<"No"<<endl;
		return 0;
	}
	T /= 2;

	while(cnt.size()!=0){
		long long C = cnt[0];
		cnt.erase(cnt.begin());
		
		if(cnt.size()==0){
			if(C>=abs(T)){
				cout<<"Yes"<<endl;
				return 0;
			}
			else{
				cout<<"No"<<endl;
				return 0;
			}
		}
		//cout<<cnt.size()<<endl;
		if(T%2!=0){
			if(C==0){
				cout<<"No"<<endl;
				return 0;
			}
			C--;
			T++;
		}
		cnt[0] += C/2;
		T /= 2;
	}
	
    return 0;
}