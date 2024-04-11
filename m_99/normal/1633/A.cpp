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
		
		while(n%7!=0){
			n++;
			if(n%10==0)n-=10;
		}
		
		cout<<n<<endl;
		
		
		
	}
	
	return 0;
}