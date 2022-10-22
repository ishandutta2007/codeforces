#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int T = 1000001;
	vector<int> p(T,-1);
	
	for(int i=2;i<T;i++){
		if(p[i]!=-1)continue;
		for(int j=i;j<T;j+=i){
			if(p[j]==-1)p[j] = i;
		}
	}
	
	vector<int> ps(T,1);
	
	for(int i=2;i<T;i++){
		int cur = i;
		int temp = 1;
		while(cur!=1){
			int pp = p[cur];
			if(temp%pp==0)temp/=pp;
			else temp *= pp;
			cur /= pp;
		}
		ps[i] = temp;
	}

	
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		map<int,int> mp;
		rep(i,n){
			scanf("%d",&a[i]);
			mp[ps[a[i]]]++;
		}
		
		int ans0=0,ans1=0;
		
		for(auto x:mp){
			ans0 = max(ans0,x.second);
			if(x.first==1||x.second%2==0){
				ans1 += x.second;
			}
		}
		
		int q;
		scanf("%d",&q);
		
		rep(i,q){
			long long w;
			scanf("%lld",&w);
			if(w==0)printf("%d\n",ans0);
			else printf("%d\n",max(ans0,ans1));
		}
		
	}
	
    return 0;
}