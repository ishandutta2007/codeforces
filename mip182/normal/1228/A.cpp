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
const ll kek=998244353;

int main() {
mipletsplay;

ll l,r;
cin>>l>>r;
int ans=-1;
for (int i=l;i<=r;i++)
{
vector <int> a(10);
int q=i;
while (q)
{
a[q%10]++;
q/=10;
}
bool ok=true;
for (int j=0;j<10;j++)
{
if (a[j]>1)
ok=false;
}
if (ok)
ans=i;
}
cout<<ans;}