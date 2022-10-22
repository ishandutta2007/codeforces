#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo N
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		
		set<int> A,B;
		
		rep(i,n){
			if(A.count(a[i]))B.insert(a[i]);
			else A.insert(a[i]);
		}
		
		int ans = 0;
		rep(i,105){
			if(!A.count(i)){
				ans += i;
				break;
			}
		}
		rep(i,105){
			if(!B.count(i)){
				ans += i;
				break;
			}
		}
		cout<<ans<<endl;
		
	}
	
    return 0;
}