#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<int> a(k);
		rep(i,k-3){
			a[i+3] = 1;
			n--;
		}
		if(n%2==1){
			a[0] = 1;
			a[1] = (n-1)/2;
			a[2] = a[1];
		}
		else{
			if(n%4==2 || n==4){
				a[0] = 2;
				a[1] = (n-2)/2;
				a[2] = a[1];
			}
			if(n%4==0){
				a[0] = n/4;
				a[1] = n/4;
				a[2] = a[0]+a[1];
			}
		}
		
		rep(i,k){
			if(i!=0)printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
		
	}
	
    return 0;
}