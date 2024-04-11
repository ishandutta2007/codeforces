#include <bits/stdc++.h>
typedef long long ll;
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
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
ll a,b,c,d;
cin>>a>>b>>c>>d;
vector <int> f(3);
f[0]=a;
f[1]=b;
f[2]=c;
sort(f.begin(),f.end());
cout<<max((ll)0,d-f[1]+f[0])+max((ll)0,d-f[2]+f[1]);}