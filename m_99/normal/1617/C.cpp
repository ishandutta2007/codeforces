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
		
		vector<int> a(n);
		vector<bool> f(n);
		int ans = 0;
		priority_queue<int> Q;
		rep(i,n){
			scanf("%d",&a[i]);
			if(a[i]<=n&&f[a[i]-1]==false){
				f[a[i]-1] = true;

			}
			else{
				Q.push(a[i]);
			}
		}
		
		for(int i=n;i>=1;i--){
			if(f[i-1]==false){
				if((Q.top()-1)/2 < i){
					ans = -1;
					break;
				}
				else{
					Q.pop();
					ans++;
				}
				
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}