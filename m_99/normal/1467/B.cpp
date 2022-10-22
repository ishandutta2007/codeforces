#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int get(int a,int b,int c){
	if(a>b&&c>b)return 1;
	if(a<b&&c<b)return 1;
	return 0;
}

int main(){

	int _t;
	scanf("%d",&_t);
	
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		if(n<3){
			printf("0\n");
			continue;
		}
		
		int ans = 0;
		rep(i,n-2){
			ans += get(a[i],a[i+1],a[i+2]);
		}
		
		int mini = 0;
		rep(i,n){
			
			rep(j,4){
				int t = 0;
				int x = a[i];
				if(i!=0&&i!=n-1)t -= get(a[i-1],a[i],a[i+1]);
				if(i-2>=0)t -= get(a[i-2],a[i-1],a[i]);
				if(i+2<n)t -= get(a[i],a[i+1],a[i+2]);
				
				if(j==0){
					a[i] = -1;
				}
				if(j==1){
					a[i] = 1000000001;
				}
				if(j==2&&i!=0){
					a[i] = a[i-1];
				}
				if(j==3&&i!=n-1){
					a[i] = a[i+1];
				}
				
				if(i!=0&&i!=n-1)t += get(a[i-1],a[i],a[i+1]);
				if(i-2>=0)t += get(a[i-2],a[i-1],a[i]);
				if(i+2<n)t += get(a[i],a[i+1],a[i+2]);
				a[i] = x;
				mini = min(mini,t);
			}
		}

		printf("%d\n",ans+mini);
		
	}
	
    return 0;
}