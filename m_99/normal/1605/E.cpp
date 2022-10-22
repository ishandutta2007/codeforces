#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int n;
	cin>>n;
	
	vector<long long> a(n),b(n);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n)scanf("%lld",&b[i]);
	
	vector<long long> v(n,0),vx(n,0);
	rep(i,n){
		if(i==0){
			v[i] = -a[i];
			vx[i] = 1;
		}
		else{
			v[i] += a[i];
			v[i] *= -1;
			vx[i] *= -1;
			v[i] += b[i];
		}
		for(int j=(1+i)*2;j<=n;j+=(i+1)){
			v[j-1] += v[i];
			vx[j-1] += vx[i];
		}
	}
	
	vector<long long> u(1000005,0),ux(1000005,0);
	
	rep(i,n){
		if(vx[i]==-1){
			vx[i] *= -1;
			v[i] *= -1;
		}
		
		if(vx[i]==0){
			u[0] += abs(v[i]);
		}
		else{
			int pos = -v[i];
			if(pos<=0){
				u[0] += v[i];
				ux[0] += vx[i];
			}
			else{
				u[0] -= v[i];
				ux[0] -= vx[i];
				if(pos<=1000000){
					u[pos] += 2*v[i];
					ux[pos] += 2*vx[i];
				}
			}
		}
	}
	rep(i,1000002){
		u[i+1] += u[i];
		ux[i+1] += ux[i];
	}
	
	int q;
	cin>>q;
	
	rep(_,q){
		long long x;
		scanf("%lld",&x);
		long long ans = u[x];
		ans += ux[x] * x;
		printf("%lld\n",ans);
	}
	
	return 0;
}