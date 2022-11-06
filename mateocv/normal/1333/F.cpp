#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

bool isprime[500005];
ll SPF[500005];
vector<ll> prime;
void sieve(int n){
    isprime[0] = isprime[1] = false;
    fore(i,2,n+1){
        if(isprime[i]) prime.push_back(i), SPF[i] = i;
        for(int j=0; j<SZ(prime)&&i*prime[j]<=n&&prime[j]<=SPF[i]; j++){
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

bool cmp(ll a, ll b){
	return a/SPF[a]<b/SPF[b]||(a/SPF[a]==b/SPF[b]&&a<b);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,500005)isprime[i]=true;
	sieve(500005);
	SPF[1]=1;
	ll a[n];
	fore(i,0,n)a[i]=i+1;
	sort(a,a+n,cmp);
	fore(i,1,n)cout<<a[i]/SPF[a[i]]<<" ";
	return 0;
}