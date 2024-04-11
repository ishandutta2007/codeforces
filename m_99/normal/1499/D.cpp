#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000
const int sz = 20000005;
int cntp[sz];
int pscnt = 0;
int p[sz];

long long get(int t,int c,int d){
	t += d;
	if(t%c!=0)return 0;
	t/=c;
	return 1LL<<cntp[t];
}

int main(){
	
	for(int i=2;i<sz;i++){
		if(cntp[i]==0){
			cntp[i] = 1;
			p[pscnt] = i;
			pscnt++;
		}
		rep(j,pscnt){
			if(p[j]>sz/i)break;
			cntp[p[j]*i] = cntp[i];
			if(i%p[j]!=0){
				cntp[p[j]*i]++;
			}
			else break;
		}
	}
	
	int t;
	cin>>t;
	
	rep(_,t){
		
		int c,d,x;
		scanf("%d %d %d",&c,&d,&x);
		long long ans = 0LL;
		for(int i=1;i*i<=x;i++){
			
			if(x%i==0){
				ans += get(x/i,c,d);
				if(i*i!=x){
					ans += get(i,c,d);
				}
			}
		}
		
		printf("%lld\n",ans);
		
	}
		
	
    return 0;
}