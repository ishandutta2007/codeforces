#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){

	
	int n;
	cin>>n;
	long long t;
	cin>>t;
	
	vector<long long> a(n),x(n);
	rep(i,n)scanf("%lld",&a[i]);

	rep(i,n){
		scanf("%lld",&x[i]);
		x[i]--;
	}
	
	rep(i,n){
		if(i==0)continue;
		if(x[i-1]>x[i]){
			cout<<"No"<<endl;
			return 0;
		}
		if(i>x[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	
	vector<int> valid(n+1,0),invalid(n+1,0);
	
	for(int i=0;i<n;i++){
		valid[i+1]++;
		valid[x[i]+1]--;
		invalid[x[i]+1]=1;
	}
	
	for(int i=1;i<n;i++)valid[i] += valid[i-1];
	
	vector<long long> ans(n);
	ans[0] = a[0]+t;
	rep(i,n){
		if(i==0){
			if(invalid[i]){
				cout<<"No"<<endl;
				return 0;
			}
		}
		else{
			if(invalid[i]){
				if(valid[i]){
					cout<<"No"<<endl;
					return 0;
				}
				ans[i-1] = a[i] + t - 1;
			}
			else{
				ans[i-1] = a[i] + t;
			}
		}
		
		
	}
	ans.back() = Inf*3-2;
	
	rep(i,n){
		if(i==0)continue;
		if(ans[i]<=ans[i-1]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	
	cout<<"Yes"<<endl;
	rep(i,n){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	
	
	
	return 0;
}