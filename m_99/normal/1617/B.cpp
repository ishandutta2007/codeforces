#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		int a,b,c;
		if(n%2==0){
			c = 1;
			n--;
			a = n/2;
			b = a+1;
		}
		else{
			c = 1;
			a = n/2;
			b = a;
			while(gcd(a,b)!=1){
				a++;
				b--;
			}
		}
		
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
	
	return 0;
}