#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
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
 
llo it[100001];
llo vis[100001];
llo pre[100001];
llo pre2[100001];
llo pre3[100001];
 
llo ac[100001];
void dnc(vector<llo> aa,vector<llo> bb,llo su=0){
	if(aa.size()<=1){
		return;
	}

	vector<llo>  cc;
	vector<llo> dd;
	vector<llo> ee;
	vector<llo> ff;
	llo x=aa.size();
	x/=2;
	for(llo i=0;i<x;i++){
		cc.pb(aa[i]);
		ee.pb(bb[i]);
	}
	for(llo i=x;i<aa.size();i++){
		dd.pb(aa[i]);
		ff.pb(bb[i]);
	}
	for(llo i=x;i<aa.size();i++){
		aa[i]=0;
	}
	for(llo i=0;i<x;i++){
		bb[i]=0;
	}
	vector<llo> zz=multiply(aa,bb);
	for(llo i=0;i<zz.size();i++){
		if((i+su)%2==0){
			llo x=(i+su)/2;
			ac[x]=(ac[x]+zz[i])%mod;
		}
	}
	dnc(cc,ee,su);
	dnc(dd,ff,su+(2*x));
 
}
llo pre4[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		pre4[i+1]=(pre4[i]+it[i])%mod;
	}
	for(llo i=0;i<m;i++){
		llo aa;
		cin>>aa;
		vis[aa]=1;
		pre[aa]+=1;
	}
	for(llo i=1;i<=n;i++){
		pre[i]+=pre[i-1];
	}
	pre2[0]=1;
	pre3[0]=1;
	llo xx=poww(2,mod-2);
	for(llo i=1;i<=n;i++){
		pre2[i]=(pre2[i-1]*2)%mod;
		pre3[i]=(pre3[i-1]*xx)%mod;
	}
	vector<llo> aa;
	vector<llo> bb;
	for(llo i=0;i<n;i++){
		aa.pb(pre2[pre[i]]);
		bb.pb(pre3[pre[i+1]]);
		ac[i]=(pre3[vis[i+1]]);
	}
	/*for(llo i=0;i<aa.size();i++){
		for(llo j=i+1;j<bb.size();j++){
			if((i+j)%2==0){
				llo x=(i+j)/2;
				ac[x]=(ac[x]+aa[i]*bb[j])%mod;
			}
		}
	}*/
	dnc(aa,bb);
 
	for(llo i=0;i<n;i++){
		ac[i]=(ac[i]*pre2[m])%mod;
		//cout<<ac[i]<<",";
	}
	for(llo i=0;i<n;i++){
		llo ii=min(i+1,n-i);
		ac[i]=(ac[i]+mod-ii)%mod;
		//cout<<ac[i]<<",";
	}
	//cout<<endl;
	llo ans=0;
	for(llo i=1;i<n;i++){
		llo ind=(i-1)/2;

		llo xx=pre2[(pre[n]-pre[i+1])];
		xx=(xx-1+mod)%mod;
		ans=(ans+xx*pre4[ind+1])%mod;
	}
 
	for(llo i=0;i<n;i++){
		ans=(ans+ac[i]*it[i])%mod;
	}
	/*for(llo i=0;i<n/2;i++){
		swap(it[i],it[n-i-1]);
 
	}
	for(llo i=0;i<n/2;i++){
		swap(vis[i+1],vis[n-i]);
	}
	for(llo i=1;i<=n;i++){
		pre[i]=pre[i-1]+vis[i];
	}
	for(llo i=0;i<n;i++){
		pre4[i+1]=pre4[i]+it[i];
		if(pre4[i+1]>=mod){
			pre4[i+1]-=mod;
		}*/
	//}
	for(llo i=0;i<n-1;i++){
		llo ind=((i+n-1+2)/2);
		llo xx=pre2[pre[i]];

		xx=(xx-1+mod)%mod;
		//cout<<i<<":"<<xx<<":"<<ind<<endl;
		//
		//cout<<((pre4[n]-pre4[ind]+mod)%mod)<<endl;
		ans=(ans+xx*((pre4[n]-pre4[ind]+mod)%mod))%mod;
	}
/*	for(llo i=1;i<n;i++){
		llo ind=((i+2))/2;
		llo xx=pre2[(pre[n]-pre[i+1])];
		xx=(xx-1+mod)%mod;
		//ans=(ans+xx*pre4[ind])%mod;
	}*/
 
	llo yy=poww((pre2[m]-1),mod-2);
	ans=(ans*yy)%mod;
	cout<<ans<<endl;
 
	//cout<<endl;
 
 
 
 
	/*for(llo i=0;i<n;i++){
		cin>>it[i];
	}
 
	for(llo i=0;i<m;i++){
 
	}
 
*/
 
 
 
 
 
 
 
	return 0;
}