#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000

int main(){
	
	int n,k;
	scanf("%d %d",&n,&k);
	k--;
	
	vector<long long> a(n),b(n);
	rep(i,n){
		scanf("%lld",&a[i]);
	}
	rep(i,n){
		scanf("%lld",&b[i]);
	}
	
	long long ng = -1LL,ok = Inf;
	
	priority_queue<array<long long,4>,vector<array<long long,4>>,greater<array<long long,4>>> CQ;
		
	rep(i,n){
		long long remain = (a[i]+1+b[i]-1)/b[i];
		long long last = 0LL;
		long long A = a[i];
		long long B = b[i];
		
		CQ.push({remain,last,A,B});
	}
	
	while(ok-ng>1LL){
		long long mid = (ok+ng)/2;
		
		auto Q = CQ;
		
		bool f = true;
		
		rep(i,k){
			auto T = Q.top();
			Q.pop();
			T[2] -= T[3] * (i - T[1]);
			if(T[2]<0){
				f=false;
				break;
			}
			T[2] += mid - T[3];
			if(T[2]<0){
				f=false;
				break;
			}
			T[1] = i+1;
			T[0] = i+1+(T[2] + 1 + T[3] - 1)/T[3];
			Q.push(T);
		}
		if(f){
			while(Q.size()>0){
				auto T = Q.top();
				Q.pop();
				T[2] -= T[3] * (k - T[1]);
				if(T[2]<0){
					f=false;
					break;
				}
			}
		}
		
		if(f)ok = mid;
		else ng=  mid;
		
	}
	
	if(ok==Inf)cout<<-1<<endl;
	else cout<<ok<<endl;
	
	return 0;
}