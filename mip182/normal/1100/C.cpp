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
const double PI=3.14159265;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
double n,r;
cin>>n>>r;
double k=2*PI/n;
double l=0,t=1000;
double ans=0;
while (t-l>=0.00000001)
{
double mid=(t+l)/2;
if (((2*mid)*(2*mid)-(r+mid)*(r+mid)*2+2*cos(k)*(r+mid)*(r+mid))>0)
{
if (abs((2*mid)*(2*mid)-(r+mid)*(r+mid)*2+2*cos(k)*(r+mid)*(r+mid))<=0.01)
ans=mid;
t=mid;

}
else
{
if (abs((2*mid)*(2*mid)-(r+mid)*(r+mid)*2+2*cos(k)*(r+mid)*(r+mid))<=0.01)
ans=mid;
l=mid;
}
//cout<<((2*mid)*(2*mid)-(r+mid)*(r+mid)*2+2*cos(k)*(r+mid)*(r+mid))<<endl;
}
cout<<setprecision(20)<<ans;
}