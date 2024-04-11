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
		cin>>n;
		
		int x=0,y=0;
		
		rep(i,n){
			int a;
			cin>>a;
			if(a%2!=i%2){
				if(i%2)x++;
				else y++;
			}
		}
		
		if(x!=y)cout<<-1<<endl;
		else cout<<x<<endl;
		
	}
		
	
	return 0;
}