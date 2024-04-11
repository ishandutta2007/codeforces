#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){
	
	long long N,A,R,M;
	cin>>N>>A>>R>>M;
	
	vector<long long> h(N);
	for(int i=0;i<N;i++)scanf("%lld",&h[i]);
	
	sort(h.begin(),h.end());
	
	vector<long long> S(N+1,0);
	for(int i=1;i<=N;i++){
		S[i] = h[i-1];
		S[i] += S[i-1];
	}
	
	long long ans = Inf;
	
	for(int i=0;i<N;i++){
		long long x = i*h[i]-S[i];
		long long y = (S.back()-S[i+1])-(N-1-i)*h[i];
		long long temp = 0;
		if(A+R>=M){
			long long m = min(x,y);
			temp = m*M;
			x-=m;
			y-=m;
		}
			
		
		temp += A*x + R*y;
		ans = min(ans,temp);
	}
	
	for(int j=0;j<2;j++){
		long long T = S.back()/N + j;
		long long x = 0,y = 0;
		for(int i=0;i<N;i++){
			if(h[i]<T){
				x+=T-h[i];
			}
			else{
				y+=h[i]-T;
			}
		}
		long long temp = 0;
		if(A+R>=M){
			long long m = min(x,y);
			temp = m*M;
			x-=m;
			y-=m;
		}
			
		
		temp += A*x + R*y;
		ans = min(ans,temp);
	}
		
	cout<<ans<<endl;	
	
	return 0;
}