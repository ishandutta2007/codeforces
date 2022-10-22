#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n;
	cin>>n;
	
	long long a,b,k;
	cin>>a>>b>>k;
	
	vector<long long> p;
	
	for(int i=0;i<n;i++){
		long long h = 0;
		cin>>h;
		h--;
		h%=a+b;
		
		p.push_back(h/a);
	}
	
	sort(p.begin(),p.end());
	
	for(int i=0;i<p.size();i++){
		k -= p[i];
		if(k<0){
			cout<<i<<endl;
			return 0;
		}
	}
	
	cout<<n<<endl;
	
    return 0;
}