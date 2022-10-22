#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		long long c,d;
		cin>>c>>d;
		
		if(abs(c-d)%2==1){
			cout<<-1<<endl;
			continue;
		}
		if(c==0&&d==0){
			cout<<0<<endl;
			continue;
		}
		if(c==d){
			cout<<1<<endl;
			continue;
		}
		cout<<2<<endl;
		
		
		
		
	}
	
	return 0;
}