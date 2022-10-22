#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000



int main(){
	
	int m,n,k,t;
	cin>>m>>n>>k>>t;
	vector<int> a(m);
	for(int i=0;i<m;i++)cin>>a[i];
	
	sort(a.begin(),a.end(),greater<int>());
	
	vector<vector<int>> r(n+2,vector<int>()),d(n+2,vector<int>());
	for(int i=0;i<k;i++){
		int ll,rr,dd;
		cin>>ll>>rr>>dd;
		r[ll].push_back(rr);
		d[ll].push_back(dd);
	}
	
	int ok = 0;
	int ng = m+1;
	while(ng-ok>1){
		int mid = (ok+ng)/2;
		int D = a[mid-1];
		int now = 0;
		int last_r = 0;
		int cost = 0;
		while(now!=n+1){
			int maxi = 0;
			for(int i=0;i<r[now+1].size();i++){
				if(d[now+1][i]<=D)continue;
				maxi = max(maxi,r[now+1][i]);
			}
			if(maxi>last_r){
				cost += abs(maxi-max(now,last_r))*2;
				last_r=maxi;
			}
			cost++;
			/*
			if(mid==3){
				cout<<now<<','<<cost<<endl;
			}*/
			now++;
		}
		if(cost<=t)ok=mid;
		else ng=mid;
	}
	
	cout<<ok<<endl;
		
	
	return 0;
	
}