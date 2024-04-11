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
		scanf("%d",&n);
		vector<int> a(n),b(n);
		rep(i,n){
			scanf("%d %d",&a[i],&b[i]);
			swap(a[i],b[i]);
		}
		
		int ok = 0,ng = n+1;
		
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			int cnt = 0;
			rep(i,n){
				int left = cnt,right = mid-cnt-1;
				if(left<=a[i]&&right<=b[i])cnt++;
				if(cnt==mid)break;
			}
			if(cnt==mid)ok = mid;
			else ng = mid;
		}
		printf("%d\n",ok);
		
	}
	
	return 0;
}