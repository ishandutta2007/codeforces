#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		int ok = 2005,ng = 0;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			bitset<2008> B;
			rep(i,mid+1)B[i] = 1;
			bitset<2008> b = B;
			rep(i,n){
				b = (b>>a[i]) | (b<<a[i]);
				b &= B;
			}
			if(b.count()>0)ok = mid;
			else ng = mid;
			
		}
		printf("%d\n",ok);
		
	}
	
	return 0;
}