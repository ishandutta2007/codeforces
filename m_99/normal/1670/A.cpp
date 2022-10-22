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
		vector<int> a(n);
		int t = 0;
		rep(i,n){
			scanf("%d",&a[i]);
			if(a[i]<0)t++;
		}
		rep(i,n){
			if(i<t){
				if(a[i]<0)continue;
				else a[i]*=-1;
			}
			else{
				if(a[i]>0)continue;
				else a[i]*=-1;
			}
		}
		auto b = a;
		sort(b.begin(),b.end());
		if(a==b)printf("YES\n");
		else printf("NO\n");
		
	}
	
    return 0;
}