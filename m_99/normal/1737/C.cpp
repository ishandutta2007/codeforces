#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> r(4),c(4);
		rep(i,4)cin>>r[i]>>c[i];
		
		bool f = false;
		rep(i,3){
			if(r[i]==r[3]&&c[i]==c[3])f = true;
		//	if(r[i]%2==r[3]%2&&c[i]%2==c[3]%2)f = true;
		}
		if(!f){
			vector<int> x = {1,1,n,n},y = {1,n,1,n};
			bool F  =false;
			
			F = true;
			if(F){
				F =false;
				rep(i,3){
					if(r[i]%2==r[3]%2&&c[i]%2==c[3]%2)F = true;
				}
			}
			if(F){
				rep(i,4){
					int m = 0;
					rep(j,3){
						m = max(m,abs(x[i]-r[j]) + abs(y[i]-c[j]));
					}
					//cout<<m<<endl;
					if(m<=1 && r[3]!=x[i] && c[3]!=y[i])F = false;
				}
			}
			if(F)f = true;
			
		}
		
		
		cout<<(f?("YES"):("NO"))<<endl;
	}	
	
	return 0;
}