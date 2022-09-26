#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
const double pi=acos(-1);
signed main()
{
double mx,a,b,m;
int n;
cin>>n>>m;
mx=(double)1e18;
while(n--){
	cin>>a>>b;
	mx=min(mx,a/b);
	}
cout<<fixed<<setprecision(10)<<m*mx;
}