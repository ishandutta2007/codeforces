#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector<int> cnt(m,0);
		rep(i,n){
			int a;
			scanf("%d",&a);
			cnt[a%m]++;
		}
		
		int ans = 0;
		if(cnt[0]>0)ans++;
		for(int i=1;i<m;i++){
			int x = i;
			int y = m-i;
			if(x>y)break;
			if(x==y){
				if(cnt[x]>0)ans++;
			}
			else{
				int t = min(cnt[x],cnt[y]);
				cnt[x] -= t;
				cnt[y] -= t;
				if(t!=0){
					ans++;
					cnt[x]--;
					cnt[y]--;
				}
				if(cnt[x]>0){
					ans += cnt[x];
				}
				if(cnt[y]>0){
					ans += cnt[y];
				}
			}
		}
		printf("%d\n",ans);
		
	}
	
    return 0;
}