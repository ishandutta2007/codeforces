#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001
vector<pair<long long,int>> get(long long n){
	vector<pair<long long,int>> ret;
	for(long long i=2;i*i<=n;i++){
		if(n%i==0){
			ret.emplace_back(i,0);
			while(n%i==0){
				n/=i;
				ret.back().second++;
			}
		}
	}
	if(n!=1)ret.emplace_back(n,1);
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long x,d;
		cin>>x>>d;
		long long c = 0;
		if(x%(d*d)!=0){
			cout<<"NO"<<endl;
			continue;
		}
		x /= d*d;
		auto p2 = get(d);
		if(p2.size()==1 && p2[0].second==1){
			while(x%d==0)x/=d;
		}
		//cout<<x<<endl;
		auto ps = get(x);
		//vector<pair<long long,int>> ps;
		
		if(ps.size()<=0)cout<<"NO"<<endl;
		else{
			if(ps.size()>=2){
				cout<<"YES"<<endl;
			}
			else{
				if(ps[0].second==1){
					cout<<"NO"<<endl;
				}
				else{
					
					if(p2.size()>=2 || p2[0].first!=ps[0].first){
						cout<<"YES"<<endl;
					}
					else{
						long long S = ps[0].second;
						S += p2[0].second * 2;
						
						long long l = p2[0].second;
						long long r = l*2;
						//cout<<l<<','<<r<<endl;
						vector<int> dp(S+1,0);
						dp[0] = 1;
						
						for(int i=l;i<r;i++){
							vector<int> ndp(S+1,0);
							rep(j,S+1){
								rep(k,100){
									if(i*k+j>S)break;
								
									ndp[i*k+j] = min(ndp[i*k+j] + dp[j], 2);
								}
								
							}
							swap(dp,ndp);
						}
						
						if(dp.back()>=2)cout<<"YES"<<endl;
						else cout<<"NO"<<endl;
						
					}
				}
			}
		}
		
	}
	
	return 0;
}