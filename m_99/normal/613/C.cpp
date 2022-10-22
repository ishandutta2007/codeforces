#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000
long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(){

	int N;
	cin>>N;
	int n = N;
	int parity = 0;
	
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin>>a[i];
		parity += a[i]%2;
	}
	
	if(parity==1){
		char c;
		for(int i=0;i<N;i++){
			if(a[i]%2==1){
				c = 'a'+i;
				break;
			}
		}
		int g = 0;
		for(int i=0;i<n;i++)g = gcd(g,a[i]);
		
		string s = "";
		for(int i=0;i<n;i++){
			for(int j=0;j<(a[i]/g)/2;j++)s += 'a'+i;
		}
		string t(s.rbegin(),s.rend());
		s += c;
		s += t;
		cout<<g<<endl;
		for(int i=0;i<g;i++)cout<<s;
		cout<<endl;
		/*
		
		
		string ans = "";
		for(int i=0;i<N;i++){
			for(int j=0;j<a[i]/2;j++)ans += 'a'+i;
		}
		string t = ans + c;
		reverse(ans.begin(),ans.end());
		ans = t+ans;
		cout<<1<<endl;
		cout<<ans<<endl;
		*/
	}
	else if(parity>=2){
		string ans = "";
		for(int i=0;i<N;i++){
			for(int j=0;j<a[i];j++)ans += 'a'+i;
		}
		cout<<0<<endl;
		cout<<ans<<endl;
	}
	else{
		int g = 0;
		for(int i=0;i<n;i++)g = gcd(g,a[i]);
		
		string s = "";
		for(int i=0;i<n;i++){
			for(int j=0;j<a[i]/g;j++)s += 'a'+i;
		}
		string t(s.rbegin(),s.rend());
		cout<<g<<endl;
		for(int i=0;i<g;i++){
			if(i%2==0)cout<<s;
			else cout<<t;
		}
		cout<<endl;
	}
	return 0;
}