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
int n;
cin>>n;
vector <int> x(n),y(n);
int sum=0;
rep (i,n){
cin>>x[i];
sum+=x[i];
}
rep(i,n){
cin>>y[i];
sum-=y[i];}
if (sum<0)
cout<<"No";
else
cout<<"Yes";}