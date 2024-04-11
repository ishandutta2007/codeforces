#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int A,B,k;
		scanf("%d %d %d",&A,&B,&k);
		vector<long long> cntA(A,0),cntB(B,0);
		
		vector<int> a(k),b(k);
		rep(i,k)scanf("%d",&a[i]);
		rep(i,k)scanf("%d",&b[i]);
		
		rep(i,k){
			a[i]--;
			b[i]--;
			cntA[a[i]]++;
			cntB[b[i]]++;
		}
		
		long long ans = k;
		ans *= k-1;
		ans /= 2;
		
		rep(i,A){
			long long temp = cntA[i];
			temp *= cntA[i]-1;
			temp /= 2;
			ans -= temp;
		}
		
		rep(i,B){
			long long temp = cntB[i];
			temp *= cntB[i]-1;
			temp /= 2;
			ans -= temp;
		}
		
		printf("%lld\n",ans);
		
	}
	
    return 0;
}