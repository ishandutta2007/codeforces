#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000



int main(){
    
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	vector<pair<int,int>> P;
	int now = -1;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(now!=a[i]){
			Label:
			if(now!=-1){
				P.emplace_back(now,cnt);
			}
			now=a[i];
			cnt=1;
		}
		else{
			cnt++;
		}
		if(i==n-1){
			P.emplace_back(now,cnt);
		}
	}
	
	long long ans = 1;
	if(P.size()==1&&P[0].first==0)ans=0;
	else{
		for(int i=1;i<P.size()-1;i++){
			if(P[i].first==0){
				ans *= P[i].second+1;
			}
		}
	}
	
	cout<<ans<<endl;
    
    return 0;
}