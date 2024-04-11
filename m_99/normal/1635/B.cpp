#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		int ans = 0;
		for(int i=1;i<n-1;i++){
			if(a[i-1]<a[i] && a[i+1]<a[i]){
				//a[i] = max(a[i-1],a[i+1]);
				a[i+1] = a[i];
				if(i+2 <= n-1)a[i+1] = max(a[i+1],a[i+2]);
				ans++;
			}
		}
		printf("%d\n",ans);
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}