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
		
		vector<int> a,c;
		rep(i,n){
			int t;
			scanf("%d",&t);
			if(a.size()==0 || a.back()!=t){
				a.push_back(t);
				c.push_back(1);
			}
			else c.back()++;
		}
		
		int ans = n-2;
		
		rep(i,a.size()){
			int cur = c[i];
			int nxt = a[i]+1;
			while(true){
				int d = distance(a.begin(),lower_bound(a.begin(),a.end(),nxt));
				if(d==a.size())break;
				cur++;
				nxt = a[d] + (a[d]-a[i]);
			}
			ans = min(ans,n-cur);
		}
		
		printf("%d\n",ans);
		
	}
		
	return 0;
}