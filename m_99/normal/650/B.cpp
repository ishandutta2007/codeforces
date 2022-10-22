#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	long long n,a,b,t;
	cin>>n>>a>>b>>t;
	
	string S;
	cin>>S;
	
	vector<long long> T(S.size(),0LL);
	
	for(int i=1;i<S.size();i++){
		if(S[i]=='w')T[i]=b+1;
		else T[i]=1;
		T[i]+=T[i-1];
	}
	
	long long ans =0LL;
	
	for(int i=0;i<S.size();i++){
		t--;
		if(S[(n-i)%n]=='w')t-=b;
		
		long long x = i;
		if(t-x*a<0)break;
		ans = max(ans,(long long)i+1);
		long long ok = 0,ng = n;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			long long y = mid;
			if(t-((min(x,y)+x+y)*a+T[mid])>=0)ok = mid;
			else ng = mid;
		}
		ans = max(ans,ok+i+1);
	}
	
	cout<<min(n,ans)<<endl;
	
	return 0;
}