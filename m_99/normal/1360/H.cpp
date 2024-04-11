#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long n,m;
		cin>>n>>m;
		
		vector<long long> a(n);
		
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			
			a[i] = stoll(s,0,2);
		}
		
		long long num = (1LL<<m) - n;
		long long ans = 0;
		long long maxi = (1LL<<m)-1;
		
		for(long long i = m-1;i>=0;i--){
			ans |= (1LL<<i);
			long long t = maxi-ans+1;
			for(int j=0;j<n;j++){
				if(ans<=a[j])t--;
			}
			if(t<num/2+1)ans ^= (1LL<<i);
		}
		
		string s(m,'0');
		for(int i=0;i<m;i++){
			if(ans&1){
				s[m-1-i]='1';
			}
			else{
				s[m-1-i]='0';
			}
			ans/=2;
		}
		cout<<s<<endl;
			
	}
	
	return 0;	
}