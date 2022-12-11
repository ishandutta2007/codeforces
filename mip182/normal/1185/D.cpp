#include <bits/stdc++.h>
typedef long long ll;
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
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
ll n;
cin>>n;
vll b(n);
rep(i,n)
cin>>b[i];
vector <ll> c=b;
sort(all(b));
if (n==2)
{
cout<<1;
return 0;
}
if ((b[n-1]-b[0])%(n-2)==0)
{
ll q=(b[n-1]-b[0])/(n-2);
bool ok=true;
int ans=-1;
for (int i=1;i<n-1;i++)
{
if (b[i-1]+q==b[i])
continue;
else
{
if (ans==-1 && b[i-1]+q==b[i+1]){
ans=i;
i++;
}
else
{
ok=false;
break;
}
}
}
if (ok){
for (int i=0;i<c.size();i++)
{
//cout<<c[i]<<" "<<b[ans]<<endl;
if (c[i]==b[ans])
{
cout<<i+1;
return 0;
}
}}
}
if ((b[n-1]-b[1])%(n-2)==0)
{
ll q=(b[n-1]-b[1])/(n-2);
bool ok=true;
int ans=-1;
for (int i=2;i<n;i++)
{
if (b[i-1]+q==b[i])
continue;
else
{
ok=false;
break;
}
}
if (ok){
rep(i,n)
{
if (c[i]==b[0])
{
cout<<i+1;
return 0;
}
}}
}
if ((b[n-2]-b[0])%(n-2)==0)
{
ll q=(b[n-2]-b[0])/(n-2);
bool ok=true;
int ans=-1;
for (int i=1;i<n-1;i++)
{
if (b[i-1]+q==b[i])
continue;
else
{
ok=false;
break;
}}
if (ok){
rep(i,n)
{
if (c[i]==b[n-1])
{
cout<<i+1;
return 0;
}
}}
}
cout<<-1;}