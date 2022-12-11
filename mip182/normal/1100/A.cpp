#include <bits/stdc++.h>
typedef long long ll;
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
int n,k;
cin>>n>>k;
vector <int> a(n);
rep(i,n)
cin>>a[i];
int ans=0;
for (int i=0;i<k;i++)
{
vector <int> b=a;
for (int j=0;i+k*j<n;j++)
b[k*j+i]=0;
int cnt1=0,cnt2=0;
for (int j=0;j<n;j++)
{
if (b[j]==-1)
cnt1++;
if (b[j]==1)
cnt2++;

}
ans=max(ans,abs(cnt1-cnt2));
}
    cout<<ans;
}