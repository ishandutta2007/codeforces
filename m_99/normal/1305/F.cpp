#include <bits/stdc++.h>
using namespace std;
#define modulo m
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int n;
	cin>>n;
	
	vector<long long> a(n);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	
	mt19937 engine(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(a.begin(),a.end(),engine);
	
	long long ans = Inf;
	long long temp = 0;
	
	vector<long long> p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	
	for(int i=0;i<p.size();i++){
		temp = 0;
		for(int j=0;j<n;j++){
			if(a[j]>=p[i])temp += min(a[j]%p[i],p[i]-(a[j]%p[i]));
			else temp += p[i]-a[j];
		}
		ans = min(ans,temp);
	}
	
	for(int i=0;i<min(n,50);i++){
		
		//long long x = a[i];
		
		for(int aa=-1;aa<=1;aa++){
			long long x = a[i]+aa;			
			
			if(x<=0)continue;
			vector<long long> P;
			for(long long j=2;j*j<x;j++){
				if(x%j==0){
					P.push_back(j);
					while(x%j==0)x/=j;
				}
			}
			
			if(x!=1)P.push_back(x);
			
			for(int j=0;j<P.size();j++){
				temp = 0;
				for(int k=0;k<n;k++){
					if(a[k]>=P[j])temp += min(a[k]%P[j],P[j]-(a[k]%P[j]));
					else temp += P[j]-a[k];
				}
				ans = min(ans,temp);
			}
		}
		
		
	}
	
	cout<<ans<<endl;
	
	return 0;
}