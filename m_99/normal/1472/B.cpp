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
		scanf("%d",&n);
		
		int c1=0,c2=0;
		rep(i,n){
			int a;
			scanf("%d",&a);
			if(a==1)c1++;
			else c2++;
		}
		
		bool f = false;
	
		for(int i=0;i<=c2;i++){
			for(int j=0;j<=c1;j++){
				int x = i*2 + j;
				int y = (c2-i)*2 + (c1-j);
				if(x==y){
					f=true;
					break;
				}
			}
			if(f)break;
		}
		if(f)printf("YES\n");
		else printf("NO\n");
		
		
	}
	
    return 0;
}