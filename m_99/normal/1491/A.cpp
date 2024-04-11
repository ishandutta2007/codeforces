#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int n,q;
	cin>>n>>q;
	int c0=0,c1=0;
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
		if(a[i]==0)c0++;
		else c1++;
	}
	
	rep(i,q){
		int t,x;
		scanf("%d %d",&t,&x);
		x--;
		if(t==1){
			if(a[x]==0){
				c0--;
				c1++;
			}
			else{
				c0++;
				c1--;
			}
			a[x] ^= 1;
		}
		else{
			if(c1>=x+1){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
	}
	
    return 0;
}