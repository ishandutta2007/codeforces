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
		rep(i,n){
			scanf("%d",&a[i]);
		}
		int ans = 0;
		rep(i,n-1){
			int x = a[i],y = a[i+1];
			if(x>y)swap(x,y);
			
			while(true){
				if(x*2>=y)break;
				x*=2;
				ans++;
			}
		}
		
		cout<<ans<<endl;
		
		
	}
	
    return 0;
}