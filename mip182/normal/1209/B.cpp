#include <bits/stdc++.h>
typedef long long ll;
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back 
#define pii pair <int, int>
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
string s;
cin>>s;
vector <int> a(n),b(n);
for (int i=0;i<n;i++)
cin>>a[i]>>b[i];
int ans=-1;
for (int i=0;i<10000;i++)
{
int cnt=0;
for (int j=0;j<n;j++)
{
if (b[j]>i)
{
if (s[j]=='1')
cnt++;
}
else
{
int y=(i-b[j])/a[j]+1;
int h=s[j]-'0';
h+=y;
if (h%2==1)
cnt++;
    
}
    
    
}
ans=max(ans,cnt);
    
    
}
cout<<ans<<endl;
}