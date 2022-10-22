#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001
	

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		vector<int> c(3,0);
		rep(i,n){
			scanf("%d",&a[i]);
			c[a[i]%3]++;
		}
		int ans = 0;
		rep(j,2){
			rep(i,3){
				if(c[i]>n/3){
					ans += c[i] - n/3;
					c[(i+1)%3] += c[i] - n/3;
					c[i] = n/3;
				}
			}
		}
		
		printf("%d\n",ans);
		
		
	}
	
    return 0;
}