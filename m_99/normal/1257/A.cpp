#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n,x,a,b;
		cin>>n>>x>>a>>b;
		if(a>b)swap(a,b);
		for(int j=0;j<x;j++){
			if(a!=1)a--;
			else{
				if(b!=n)b++;
			}
		}
		cout<<b-a<<endl;
	}
	
	
    return 0;
}