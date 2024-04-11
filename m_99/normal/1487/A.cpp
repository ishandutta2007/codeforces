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
		scanf("%d",&n);
		vector<int> a(n);
		int mini = Inf;
		rep(i,n){
			scanf("%d",&a[i]);
			mini = min(mini,a[i]);
		}
		
		int ans = 0;
		rep(i,n){
			if(a[i]==mini)continue;
			ans++;
		}
		
		printf("%d\n",ans);
		
	}
		
    return 0;
}