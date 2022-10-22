#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		string x;
		cin>>x;
		
		bool f = false;
		
		string a(n,'0'),b(n,'0');
		for(int i=0;i<n;i++){
			if(x[i]=='0'){
				a[i]='0';
				b[i]='0';
			}
			else if(x[i]=='1'){
				if(!f){
					a[i] = '0';
					b[i] = '1';
					f=true;
				}
				else{
					a[i] = '1';
					b[i] = '0';
				}
			}
			else{
				if(!f){
					a[i]='1';
					b[i]='1';
				}
				else{
					a[i] = '2';
					b[i] = '0';
				}
			}
		}
		cout<<a<<endl<<b<<endl;
	}

    return 0;
}