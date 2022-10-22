#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
 
 
int main(){
	
	vector<vector<int>> Y(200001);
	for(int i=1;i<=200000;i++){
		for(int j=i;j<=200000;j+=i)Y[j].push_back(i);
	}
	
	
	int _t;
	cin>>_t;
	vector<bool> e(200001,false);
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
			e[a[i]] = true;
		}
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end());
		reverse(a.begin(),a.end());
		

		int ans = 0;
		rep(i,a.size()){
			ans = max(ans,a[i]);
			int c = 0;
			for(int j=i+1;j<a.size();j++){
				if(a[i]%a[j]==0)continue;
				ans = max(ans,a[i]+a[j]);
				c++;
				for(int k=j+1;k<a.size();k++){
					if(a[i]%a[k]==0||a[j]%a[k]==0)continue;
					ans = max(ans,a[i]+a[j]+a[k]);
					break;
				}
				if(c==2)break;
			}
		}
		
		printf("%d\n",ans);
		rep(i,a.size()){
			e[a[i]] = false;
		}
	}
	
	return 0;
}