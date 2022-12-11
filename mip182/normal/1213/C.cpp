#include <bits/stdc++.h>
typedef long long ll;
#define vstroku() to_string()
#define vchislo() to_ulong()
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back 
#define pii pair <int, int>
#define F first
#define S second
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
int q;
cin>>q;
for (int jj=0;jj<q;jj++)
{
ll n,m;
cin>>n>>m;
ll q=n/m;
ll sum=m%10;
ll f=2*(m%10);
int j=1;
while ((f%10)!=(m%10))
{
sum+=f%10;
f+=m%10;
j++;
}
ll ans=sum*(q/j);
ll h=m%10;
for (int i=1;i<=q%j;i++)
{
ans+=h%10;
h+=m%10;
    
}
cout<<ans<<endl;
}}