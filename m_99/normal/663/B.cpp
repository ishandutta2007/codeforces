#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 2000000000000000000


int main(){
	
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		s.erase(s.begin(),s.begin()+4);
		long long now = 1989;
		
		for(int j=0;j<s.size();j++){
			long long x = 10;
			for(int k=0;k<j;k++)x*=10;
			long long y = stoll(s.substr(s.size()-1-j));
			if(now%x <= y){
				now /= x;
				now *= x;
				now += y;
			}
			else{
				now /= x;
				now *= x;
				now += y;
				now += x;
			}
			now++;
		}
		
		cout<<now-1<<endl;
	}
	
	return 0;
}