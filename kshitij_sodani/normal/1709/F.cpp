#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
int n,k,f;
const llo _ = 1 << 20 , mod = 998244353 , G = 3;
 
using cd = complex<double>;
const double PI = acos(-1);
// llo n;
llo upd(llo x) {
    return x + (x >> 31 & mod);
}
llo add(llo x , llo y) {
    return upd(x + y - mod);
}
llo sub (llo x , llo y){
    return upd(x - y);
}
llo mul (llo a, llo b) {
    return 1ll*a*b%mod;
}
llo poww(long long a , llo b) {
    llo tms = 1;
    while (b) {
        if(b & 1) tms = tms * a % mod;
        a = a * a % mod; b >>= 1;}
    return tms;
}
 
llo dir[_] , need , invnd , w[_];
void init(llo len){
	static llo L = 1; need = 1;
	while (need < len) need <<= 1;
	invnd = poww(need , mod - 2);
	for (llo i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	for (llo &i = L ; i < need ; i <<= 1) {
        w[i] = 1;
        llo wn = poww(G , mod / i / 2);
        for(llo j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % mod;
    }
}
 
void dft(vector < llo > &arr , llo tmod){
	arr.resize(need);
	for (llo i = 1 ; i < need ; ++i) {
        if (i < dir[i]) swap(arr[i] , arr[dir[i]]);
	}
	for(llo i = 1 ; i < need ; i <<= 1) {
		for (llo j = 0 ; j < need ; j += i << 1) {
			for (llo k = 0 ; k < i ; ++k) {
				llo x = arr[j + k] , y = 1ll * arr[i + j + k] * w[i + k] % mod;
				arr[j + k] = add(x , y); arr[i + j + k] = sub(x , y);
			}
		}
	}
	if(tmod == -1) {
        reverse(arr.begin() + 1 , arr.end());
        for(auto &t : arr) {
            t = 1ll * t * invnd % mod;
        }
    }
}
 
vector<llo> multiply(vector<llo> const& a, vector<llo> const& b) {
    init(a.size()+b.size());
   vector<llo> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    dft(fa, 1);
    dft(fb, 1);
    for (llo i = 0; i < need; i++) {
        fa[i] = 1ll * fa[i] * fb[i] % mod;
    }
    dft(fa, -1);
    return fa;
}
vector<llo> pre[20];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k>>f;
	for(int i=n;i>=1;i--){
		if(i==n){
			for(int j=0;j<=k;j++){
				pre[i].pb(1);
			}
		}
		else{
			vector<llo> cur=multiply(pre[i+1],pre[i+1]);
			/*for(auto j:cur){
				cout<<j<<",,";
			}
			cout<<endl;
			for(auto j:pre[i+1]){
				cout<<j<<":";
			}
			cout<<endl;*/
			for(int j=0;j<=k;j++){
				pre[i].pb(0);
			}	
			llo su=0;
			for(int j=cur.size()-1;j>=0;j--){
				su=(su+cur[j]);
				if(su>=mod){
					su-=mod;
				}
				if(j<=k){
					pre[i][j]=su;
					pre[i][j]=(pre[i][j]+cur[j]*(k-j))%mod;
				}
			}
		}

		
		
	}		
	llo ans=0;
/*	for(auto j:pre[1]){
		cout<<j<<",";
	}
	cout<<endl;*/
		for(int j=0;j<=k;j++){
			if(j<pre[1].size() and f-j<pre[1].size()){
				ans=(ans+pre[1][j]*pre[1][f-j])%mod;
				continue;
			}
			
		}
		cout<<ans<<endl;




	return 0;
}