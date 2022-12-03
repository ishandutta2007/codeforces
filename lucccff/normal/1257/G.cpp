/*#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

const int MAXN = 1 << 22, G = 3, MO = 998244353;

long long xi[MAXN+10],p[MAXN+10],q[MAXN+10],rev[MAXN+10];
long long a[MAXN+10],b[MAXN+10],c[MAXN+10],d[MAXN+10],s,t[MAXN+10];

inline LL fpow(LL n, LL k) {
    LL t = 1;
    while(k) {
        if(k & 1) t = (t * n) % MO;
        n = (n * n) % MO;
        k >>= 1;
    }
    return t;
}

inline void ntt(LL *arr, int f,int n) {
    for(int i = 0; i < n; i++) {
        if(i < rev[i]) std::swap(arr[i], arr[rev[i]]);
    }
    for(int i = 1; i < n; i <<= 1) {
        LL gn = fpow(G, (MO - 1) / (i << 1));
        if(f == -1) gn = fpow(gn, MO - 2);
        for(int j = 0; j < n; j += i << 1) {
            LL w = 1;
            for(int k = 0; k < i; k++) {
                LL x = arr[j + k], y = w * arr[j + k + i] % MO;
                arr[j + k] = (x + y) % MO;
                arr[j + k + i] = ((x - y) % MO + MO) % MO;
                w = (w * gn) % MO;
            }
        }
    }
}

void work() {
    int x=1,i,j,k,l,y;
    while(x<s) {
        for(i=0;i<s;i+=x<<1) {
            if (i+x>=s) continue;
            if (i+(x<<1)>=s) {
                l=t[s]-t[i];
            }
            else {
                l=t[i+(x<<1)]-t[i];
            }
            y=1;
            k=0;
            while(y<l) {
                y<<=1;
                k++;
            }
            for(int i = 0; i < y; i++) {
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
            }
            for(j=0;j<t[i+x]-t[i];j++) p[j]=xi[t[i]+j];
            for(;j<y;j++) p[j]=0;
            for(j=0;j<l-t[i+x]+t[i];j++) q[j]=xi[t[i+x]+j];
            for(;j<y;j++) q[j]=0;
            ntt(p,1,y);
            ntt(q,1,y);
            for(j=0;j<y;j++) p[j]=(p[j]*q[j])%MOD;
            ntt(p,-1,y);
            k=fpow(y,MO-2);
            for(j=0;j<l;j++) xi[t[i]+j]=(p[j]*k)%MOD;
        }
        x<<=1;
    }
}

int main(){
    long long i,j,k,l,m,n;
    cin>>n;
    j=1;
    l=1;
    m=MOD;
    b[1]=c[1]=d[1]=1;
    for(i=2;i<=n;i++) {
        c[i]=c[m%i]*(m-m/i)%MOD;
        j=(j*i)%MOD;
        l=(l*c[i])%MOD;
        b[i]=j;
        d[i]=l;
    }
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    rev[0]=0;
    sort(a,a+n);
    s=0;
    i=0;
    m=0;
    t[0]=0;
    while(i<n) {
        j=i;
        while(i<n&&a[j]==a[i]) i++;
        //work(i-j,m);
        s++;
        t[s]=i-j+1;
    }
    sort(t,t+s);
    for(i=1;i<=s;i++) {
        t[i]+=t[i-1];
    }


    for(i=0;i<n+s;i++) {
        xi[i]=1;
    }

    work();
    cout<<xi[(n+1)/2];
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
const int N=262144,md=998244353;
int n,tot[3000005],m,k[N],rev[N*2],W[N],lim,_ilim;
vector<int>vc;
inline int pow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=(u64)a*a%md)if(b&1)res=(u64)res*a%md;
	return res;
}
void initFFT(int n){
	for(lim=1;lim<n;lim<<=1);_ilim=pow(lim,md-2);
}
void init(){
	for(int i=1;i<N;i<<=1){
		const int g=pow(3,(md-1)/(i<<1));
		W[i]=1;
		for(int j=1;j<i;++j)W[i+j]=W[i+(j-1)]*(u64)g%md;
	}
	for(int i=1;i<=N;i<<=1)
	for(int j=1;j<i;++j)rev[i+j]=(rev[i+j/2]>>1)|((j&1)*(i/2));
}
void DFT(int*b){
	static u64 a[N];
	for(int i=0;i<lim;++i)a[i]=b[rev[lim+i]];
	for(int i=1;i<lim;i<<=1)
	for(int j=0;j<lim;j+=i<<1)
	for(int k=0;k<i;++k){
		const u64 x=a[j+k],y=a[j+k+i]*W[i+k]%md;
		a[j+k]+=y,a[j+k+i]=x+md-y;
	}
	for(int i=0;i<lim;++i)b[i]=a[i]%md;
}
void IDFT(int*a){
	DFT(a),reverse(a+1,a+lim);
	for(int i=0;i<lim;++i)a[i]=(u64)a[i]*_ilim%md;
}
void solve(int l,int r,vector<int>&vc){
	if(l==r){
		vc.reserve(k[l]);
		for(int i=0;i<k[l];++i)vc.emplace_back(1);
	}else{
		const int mid=(l+r)/2;
		vector<int>L,R;
		solve(l,mid,L),solve(mid+1,r,R);
		int sz=L.size()+R.size()-1;
		initFFT(sz);
		static int A[N],B[N];
		for(int i=0;i<lim;++i)A[i]=B[i]=0;
		for(int i=0;i<(int)L.size();++i)A[i]=L[i];
		for(int i=0;i<(int)R.size();++i)B[i]=R[i];
		DFT(A),DFT(B);
		for(int i=0;i<lim;++i)A[i]=(u64)A[i]*B[i]%md;
		IDFT(A);
		sz=min(sz,n/2+1);
		vc.reserve(sz);
		for(int i=0;i<sz;++i)vc.emplace_back(A[i]);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	cin>>n;
	for(int i=1,x;i<=n;++i)cin>>x,++tot[x];
	for(int i=1;i<=3e6;++i)if(tot[i])k[++m]=tot[i]+1;
	solve(1,m,vc);
	cout<<vc[n/2]<<'\n';
	return 0;
}