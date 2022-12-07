#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

const int MAXN=100000000;
//bool notprime[MAXN+1];// false  true 
bitset <MAXN+10> np;
unsigned int ans,n,a,b,c,d;

unsigned int f(unsigned int k) {
    return a*k*k*k+b*k*k+c*k+d;
}

void init(){
    //memset(notprime,false,sizeof(notprime));
    np.reset();
    unsigned int p=2,q=f(2);
    while(p<=n) {
        ans+=f(2)*(n/p);
        if (1ll*p*2>n) break;
        p*=2;
    }
    for(int j=4;j<=n;j+=2) {
        int l=j-j/6*6;
        if (l==1||l==5) np.set(j/3-1);
    }
    p=3;
    q=f(3);
    while(p<=n) {
        ans+=f(3)*(n/p);
        if (1ll*p*3>n) break;
        p*=3;
    }
    for(int j=9;j<=n;j+=3) {
        int l=j-j/6*6;
        if (l==1||l==5) np.set(j/3-1);
    }
    for(int i=1;i<=n/6+1;i++) {
        int k=i*6-1;
        if(!np.test(i*2-2)){
            unsigned int p=k,q=f(k);
            while(p<=n) {
                ans+=f(k)*(n/p);
                if (1ll*p*k>n) break;
                p*=k;
            }
            if (k<=n/k) for(int j=k*k;j<=n;j+=k) {
                int l=j-j/6*6;
                if (l==1||l==5) np.set(j/3-1);
            }
        }
        k=i*6+1;
        if(!np.test(i*2-1)){
            unsigned int p=k,q=f(k);
            while(p<=n) {
                ans+=f(k)*(n/p);
                if (1ll*p*k>n) break;
                p*=k;
            }
            if (k<=n/k) for(int j=k*k;j<=n;j+=k) {
                int l=j-j/6*6;
                if (l==1||l==5) np.set(j/3-1);
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>a>>b>>c>>d;
    init();
    cout<<ans<<endl;
    return 0;
}