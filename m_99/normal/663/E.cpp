#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 2000000000000000000

template <typename T>
void fwt(vector<T>& f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                T x = f[j], y = f[j | i];
                f[j] = x + y, f[j | i] = x - y;
            }
        }
    }
}
template <typename T>
void ifwt(vector<T>& f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                T x = f[j], y = f[j | i];
                f[j] = (x + y) / 2, f[j | i] = (x - y) / 2;
            }
        }
    }
}

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<string> s(n);
	for(int i=0;i<n;i++)cin>>s[i];
	
	vector<long long> x(1<<n,0),y(1<<n,0);
	
	for(int i=0;i<m;i++){
		int t = 0;
		for(int j=0;j<n;j++){
			t *= 2;
			t += s[j][i]-'0';
		}
		x[t] ++;
	}
	
	for(int i=0;i<(1<<n);i++){
		int c = 0;
		for(int j=0;j<n;j++){
			if((i>>j)&1)c++;
		}
		
		y[i] = min(c,n-c);
	}
	
	fwt(x);
	fwt(y);
	vector<long long> z(1<<n);
	for(int i=0;i<(1<<n);i++){
		z[i] = x[i]*y[i];
	}
	
	ifwt(z);
	
	long long ans = Inf;
	
	for(int i=0;i<(1<<n);i++){
		ans = min(ans,z[i]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}