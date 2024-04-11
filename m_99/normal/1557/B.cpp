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
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		{
			vector<int> t = a;
			sort(t.begin(),t.end());
			
			rep(i,n){
				a[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),a[i]));
			}
		}
		
		rep(i,n-1){
			if(a[i]+1!=a[i+1])k--;
		}
		
		if(k>=1)printf("YES\n");
		else printf("NO\n");
		
		
		
	}
	
	return 0;
}