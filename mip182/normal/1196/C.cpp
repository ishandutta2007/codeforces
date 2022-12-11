#include <bits/stdc++.h>
typedef long long ll;
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
const int INF = 100000;
const long long kek=998244353;

int main() {
mipletsplay;

int q;
cin>>q;
for (int i=0;i<q;i++)
{
int n;
cin>>n;
int answer=1;
ll xl=-INF,xr=INF,yu=INF,yd=-INF;
for (int j=0;j<n;j++)
{
int x,y,a1,a2,a3,a4;
cin>>x>>y>>a1>>a2>>a3>>a4;
if (a1==0)
{
if (xl<=x)
xl=x;
}
if (a2==0)
{
if (yu>=y)
yu=y;
}
if (a4==0)
{
if (yd<=y)
yd=y;
}
if (a3==0)
{
if (xr>=x)
xr=x;
    
}}
//cout <<answer<<" "<< xl<<" "<< xr<< " "<<yu<<" "<<yd<<endl;
if (xl<=xr && yu>=yd)
cout << 1<<" "<<(xl+xr)/2<<" "<< (yu+yd)/2<<endl;
else
cout << 0<<endl;
}
    


}