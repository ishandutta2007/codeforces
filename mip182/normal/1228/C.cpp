#include <bits/stdc++.h>
typedef long long ll;
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define vi vector <int>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll mod=1e9+7;

ll modexp(ll x, ll y, ll N)
{ x=x%N;
  if (y == 0) return 1;
  ll z = modexp(x, y / 2, N);
  if (y % 2 == 0)
    return ((z%N)*(z%N))%N;
  else
    return ((((x%N)*(z%N))%N)*(z%N))%N;
}

int main() {
mipletsplay;
ll x,n;
cin>>x>>n;
vector <ll> primes;
for (ll i=2;i*i<=x;i++)
{
if (x%i==0)
{
primes.pb(i);
while (x%i==0)
x/=i;
}
}
if (x>1)
primes.pb(x);
ll ans=1;
for (int i=0;i<primes.size();i++)
{
ll k=primes[i];
ll q=n;
ll u=0;
ll d=1;
while (q>=k)
{
u++;
q/=k;
}

while (d<=u){
ans*=modexp(primes[i],n/k,mod);
ans%=mod;
//cout<<k<<endl;
k*=primes[i];
d++;
}
}
cout<<ans<<endl;
}