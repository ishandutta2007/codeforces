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
bool c[10005];
int f[1000];
for(int i=0;i<20;++i){
	if(i==1||i==2)f[i]=1;
	else f[i]=f[i-1]+f[i-2];
	c[f[i]]=1;
	}
int n;
cin>>n;
for(int i=1;i<=n;++i){
	if(c[i])cout<<'O';
	else cout<<'o';
	}
}