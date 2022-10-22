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
		
		vector<int> l(n),r(n),c(n);
		rep(i,n){
			scanf("%d %d %d",&l[i],&r[i],&c[i]);
		}
		
		map<int,int> L,R;
		map<pair<int,int>,int> LR;
		rep(i,n){
			if(L.count(l[i])){
				L[l[i]] = min(L[l[i]],c[i]);
			}
			else{
				L[l[i]] = c[i];
			}
			
			if(R.count(r[i])){
				R[r[i]] = min(R[r[i]],c[i]);
			}
			else{
				R[r[i]] = c[i];
			}
			
			if(LR.count(make_pair(l[i],r[i]))){
				LR[make_pair(l[i],r[i])] = min(LR[make_pair(l[i],r[i])],c[i]);
			}
			else{
				LR[make_pair(l[i],r[i])] = c[i];
			}
			/*
			for(auto a:L){
				cout<<a.first<<','<<a.second<<endl;
			}
			*/
			
			int ll,rr;
			{
				auto it = L.begin();
				ll = (*it).first;
			}
			
			{
				auto it=  R.end();
				it--;
				rr = (*it).first;
			}
			//cout<<ll<<','<<rr<<endl;
			int ans = 2000000005;
			if(LR.count(make_pair(ll,rr))){
				ans = min(ans,LR[make_pair(ll,rr)]);
			}
			ans = min(ans,L[ll] + R[rr]);
			
			printf("%d\n",ans);
			
		}
			
			
			
		
	}
	
	return 0;
}