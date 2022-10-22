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
		cin>>n;
		vector<long long> b(n);
		long long s = 0;
		rep(i,n){
			scanf("%lld",&b[i]);
			s += b[i];
		}
		long long S = n;
		S *= n+1;
		S /= 2;
		
		if(s%S!=0){
			cout<<"NO"<<endl;
			continue;
		}
		s /= S;
		
		vector<long long> a(n,0);
		bool f = true;
		rep(i,n){
			long long d = b[i] - b[(i+n-1)%n];
			d -= s;
			if(d%n!=0){
				f = false;
				break;
			}
			a[i] = d/(-n);
			if(a[i]<=0)f = false;
		}
		rep(i,n){
			s -= a[i];
		}
		//if(s!=0)f = false;
		if(!f)cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			rep(i,n){
				if(i!=0)printf(" ");
				printf("%lld",a[i]);
			}
			cout<<endl;
		}
		
		
	}
	
	return 0;
}