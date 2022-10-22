#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n),b(n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)scanf("%d",&b[i]);
		
		bool f = true;
		rep(i,n){
			if(a[i]>b[i])f = false;
			int x = i;
			int y = x+1;
			y %= n;
			if(b[x] >= b[y]+2 && a[x] != b[x])f = false;
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	
    return 0;
}