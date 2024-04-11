#include <bits/stdc++.h>
typedef long long ll;
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j)
#define pb push_back
#define pf push_front
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define rep(i, n) for (int i = 0; i < (n); i++)
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
ll h,n;
cin>>h>>n;
vector <ll> p(n+1);
p[0]=0;
for (int i=n;i>=1;i--)
cin>>p[i];
ll ans=0;
ll cur=h;
ll c=n;
while (cur>0)
{
//cout<<cur<<endl;
if (cur-2<=0)
cur=-1;
else
{
if (cur>p[c-1]+1)
cur=p[c-1]+1;
else
{
if (p[c-1]==p[c-2]+1)
cur=p[c-2],c-=2;
else
{
//cout<<cur<<endl;
ans++;
cur=p[c-1]-1;
c--;
}
}
    
    
}
    
    
}
cout<<ans<<endl;
}
}