#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
#define InfL 4000000000000000001
long long f[60];

long long get(long long n){
	long long ret = 0;
	for(int i=59;i>=0;i--){
		if(n>=f[i]){
			n -= f[i];
			ret |= 1LL<<i;
		}
	}
	return ret;
}

int main() {
	
	f[0] = 1;
	f[1] = 1;
	for(int i=2;i<60;i++){
		f[i] = f[i-1] + f[i-2];
	}
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<long long> c(n);
		rep(i,n)cin>>c[i];
		if(n==1){
			if(c[0]==1)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			continue;
		}
		vector<long long> v0(n),v1(n);
		rep(i,n){
			v0[i] = get(c[i]);
			v1[i] = get(c[i]-1);
			//cout<<v0[i]<<','<<v1[i]<<endl;
		}
		
		vector sum(n+1,vector<long long>(n+1,0));
		vector f(1+n,vector<bool>(n+1,true));
		rep(i,n){
			sum[i][0] = 0;
			f[i][0] = true;
			long long cc = 0;
			bool cf = true;
			rep(j,n){
				if(i+j>=n)break;
				if(cc & v0[i+j]){
					cf = false;
				}
				else cc |= v0[i+j];
				sum[i][j+1] = cc;
				f[i][j+1] = cf;
			}
		}
	
		bool ff = false;
		
		rep(i,n){
			for(int j=i+1;j<n;j++){
				if(f[0][i]==false)continue;
				
				if(f[i+1][j-i-1]==false)continue;
				if(f[j+1][n-j-1]==false)continue;
				long long cc = 0;
				cc |= sum[0][i];
				if(cc&sum[i+1][j-i-1])continue;
				cc |= sum[i+1][j-i-1];
				if(cc&sum[j+1][n-j-1])continue;
				cc |= sum[j+1][n-j-1];
				
				if(cc&v1[i])continue;
				cc |= v1[i];
				if(cc&v1[j])continue;
				cc |= v1[j];
				
				if(cc&1)continue;
				if(cc&2)continue;
				
				for(int k=2;k<60;k++){
					if((cc>>k)&1){
						cc ^= 1LL<<k;
					}
					else break;
				}
				//cout<<cc<<endl;
				if(cc==0){
					ff = true;
					goto L;
				}
			}
		}
		L:;
		if(ff)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
    return 0;
}