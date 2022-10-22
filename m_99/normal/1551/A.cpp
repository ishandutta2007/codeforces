#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		int c1 = n/3,c2 = n/3;
		if(n%3==1)c1++;
		if(n%3==2)c2++;
		
		cout<<c1<<' '<<c2<<endl;
		
		
	}
	
	return 0;
}