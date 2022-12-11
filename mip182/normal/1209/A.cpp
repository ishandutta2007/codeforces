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
vector <int> a(n);
for (int i=0;i<n;i++)
cin>>a[i];
sort(a.begin(),a.end());
vector <int> b(n,0);
int cnt=0;
for (int i=0;i<n;i++)
{
if (b[i]==0)
{
int q=a[i];
b[i]=1;
cnt++;
for (int j=i+1;j<n;j++)
{
if (b[j]==0&&a[j]%q==0)
b[j]=1;
}
}
    
    
}
cout<<cnt;}