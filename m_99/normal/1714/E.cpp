#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main() {
   
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		
		rep(i,n){
			if(a[i]%10==5)a[i] += 5;
			else if(a[i]%10!=0){
				while(a[i]%10!=2){
					a[i] += a[i]%10;
				}
			}
		}
		bool f0 = false,f1 = false;
		rep(i,n){
			if(a[i]%10==0)f0 = true;
			if(a[i]%10==2)f1 = true;
		}
		if(f0){
			bool ans = true;
			rep(i,n){
				if(a[i]!=a[0])ans = false;
			}
			if(ans)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else{
			set<int> s;
			rep(i,n)s.insert(a[i]%20);
			if(s.size()==1)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		
	}
	
    return 0;
}