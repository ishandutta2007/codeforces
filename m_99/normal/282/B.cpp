#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n;
	cin>>n;
	
	string s = "";
	int a = 0,b = 0;
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(abs((a+x)-b)<=500){
			s += 'A';
			a += x;
		}
		else{
			s += 'G';
			b += y;
		}
	}
	
	cout<<s<<endl;
		
	
	return 0;
	
}