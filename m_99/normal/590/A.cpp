#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	
	rep(i,n)scanf("%d",&a[i]);
	
	vector<bool> f(n,false);
	
	for(int i=1;i<n-1;i++){
		if(a[i-1]!=a[i]&&a[i]!=a[i+1])f[i] = true;
	}
	
	vector<int> l,r;
	bool F = false;
	rep(i,n){
		if(f[i]){
			if(F){
				r.back() = i;
			}
			else{
				F = true;
				l.push_back(i);
				r.push_back(i);
			}
		}
		else{
			F = false;
		}
	}
	
	int ans = 0;
	
	for(int i=0;i<l.size();i++){
		ans = max((r[i]-l[i]+2)/2,ans);
		int L = l[i],R = r[i];
		rep(j,1000000){
			if(L==R){
				if(j%2==0){
					a[L] ^= 1;
				}
			}
			if(L>=R)break;
			if(j%2==0){
				a[L] ^= 1;
				a[R] ^= 1;
			}
			L++;
			R--;
		}
		
	}
	
	cout<<ans<<endl;
	rep(i,n){
		if(i!=0)printf(" ");
		printf("%d",a[i]);
	}
	cout<<endl;
	
    return 0;
}