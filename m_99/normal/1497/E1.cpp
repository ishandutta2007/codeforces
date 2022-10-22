#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
const int sz = 10000001;
int minp[sz];

int main(){
	
	for(int i=2;i<sz;i++){
		if(minp[i]!=0)continue;
		for(int j=i;j<sz;j+=i){
			minp[j] = i;
		}
	}
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		set<vector<int>> S;
		int ans = 1;
		rep(i,n){
			set<int> s;
			while(a[i]!=1){
				int p = minp[a[i]];
				if(s.count(p))s.erase(p);
				else s.insert(p);
				a[i] /= p;
			}
			vector<int> t;
			for(auto x:s)t.push_back(x);
			if(!S.count(t))S.insert(t);
			else{
				S.clear();
				S.insert(t);
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	
    return 0;
}