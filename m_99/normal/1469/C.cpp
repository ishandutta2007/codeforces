#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		vector<int> h(n);
		rep(i,n){
			scanf("%d",&h[i]);
		}
		
		int a = h[0],b = h[0];
		bool f = true;
		rep(i,n){
			if(i==0)continue;
			
			a -= k-1;
			b += k-1;
			
			int x = h[i];
			int y = h[i]+k-1;
			
			a = max(a,x);
			b = min(b,y);
			
			if(a>b){
				f=false;
				break;
			}
			
		}
		//cout<<a<<','<<b<<endl;
		if(f){
			if(a!=h.back())f=false;
		}
		
		if(f)printf("Yes\n");
		else printf("No\n");
		
		
		
	}
	
    return 0;
}