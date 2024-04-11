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
#define F first
#define S second
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const int INF = 1e9;
const int kek=998244353;

int main() {
mipletsplay;
int n,h,m;
cin>>n>>h>>m;
vector <int> a(n);
for (int i=0;i<n;i++)
a[i]=h;
for (int i=0;i<m;i++)
{
 int l,r,x;
 cin>>l>>r>>x;
 for (int j=l-1;j<r;j++)
 a[j]=min(a[j],x);
}
int sum=0;
for (int i=0;i<n;i++)
{
sum+=a[i]*a[i];   
}
cout<<sum;
}