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
int n,a,b;
cin>>n>>a>>b;
vector <char> c(n);
for (int i=0;i<n;i++)
cin>>c[i];
ll sum=0;
vector <int> col(2);
col[0]=a;
col[1]=b;
bool ok=true;
for (int i=0;i<n/2;i++)
{
if (c[i]=='2'&&c[n-i-1]=='2')
sum+=2*min(a,b);
else
{
if (((c[i]!='2')&&(c[n-1-i]=='2'))||((c[i]=='2')&&(c[n-1-i]!='2')))
sum+=col[min(c[i]-'0',c[n-i-1]-'0')];
else
{
if (c[i]!=c[n-1-i]){
ok=false;
//cout<<i<<endl;
}
}
}
}
if (n%2==1&&c[n/2]=='2')
sum+=min(a,b);
if (ok)
cout<<sum;
else
cout<<-1;
}