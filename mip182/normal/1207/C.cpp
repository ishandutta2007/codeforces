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

int t;
cin>>t;
for (int jj=0;jj<t;jj++)
{
ll n,a,b;
cin>>n>>a>>b;
string s;
cin>>s;
ll ans=0;
vector < pair <ll,ll> > pos;
int j=1;
for (int i=1;i<n;i++)
{
if (s[i]==s[i-1])
j++;
else
{
pos.pb({j,s[i-1]-'0'});
j=1;
}
}
pos.pb({j,0});

for (int i=1;i<pos.size()-1;i++)
{
ll k=pos[i].first;
if (pos[i].second==0)
{
if (k==1)
ans+=a;
else{
if (b*(k-1)>=2*a)    
ans+=k*a+2*a+k*b-b;
else
ans+=2*b*k-2*b+k*a;
}
}
else
{
ans+=(k+1)*2*b+k*a;
    
}
}
if (pos.size()==1){
ans=b*(pos[0].first+1)+a*pos[0].first;
}
else{
ll k=pos[0].first;
ans+=k*b+(k-1)*a+2*a;
k=pos[pos.size()-1].first;
ans+=k*b+(k-1)*a+2*a;}
cout<<ans<<endl;

    
    
    
}}