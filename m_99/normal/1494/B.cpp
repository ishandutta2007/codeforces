#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		array<int,4> A;
		rep(i,4)cin>>A[i];
		bool f = false;
		rep(i,1<<4){
			auto B = A;
			rep(j,4){
				if((i>>j)&1){
					B[j] --;
					B[(j+1)%4]--;
				}
			}
			
			bool F = true;
			rep(j,4){
				if(B[j]<0)F=false;
				if(B[j]>n-2)F=false;
			}
			if(F){
				f=true;
				break;
			}
			
		}
		
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
    return 0;
}