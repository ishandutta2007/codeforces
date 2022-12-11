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
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;

int n;
cin>>n;
vector <int> a(2*n);
a[0]=2*n;
a[n]=2*n-1;
for (int i=1;i<n;i++)
{
if (i%2==1)
{
a[i]=(i-1)*2 +1;
a[(n+i)%(2*n)]=i*2;
    
}
else
{
    a[(n+i)%(2*n)]=(i-1)*2 +1;
    a[i]=i*2;
}
}
if (n%2==0)
{
    cout<<"NO";
    return 0;
}
else{
  cout<<"YES"<<endl;
for (int i=0;i<2*n;i++)
cout<<a[i]<<" ";
}

}