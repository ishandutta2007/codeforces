#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long c = 0;
		for(int i=0;i<30;i++){
			long long a = c + (1LL<<(i));
			long long b = a + (1LL<<(i+1));
			cout<<"? "<<a<<' '<<b<<endl;
			long long ret = 0;
			cin>>ret;
			if(ret%(1LL<<(i+1))==0){
				c -= 1LL<<i;
			}
		}
		cout<<"! "<<-c<<endl;
		
		
	}
		
	return 0;
}