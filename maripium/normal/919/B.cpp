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
int sumdig(int x){
	int ans=0,tmp=x;
	while(tmp>0){
		ans+=tmp%10;
		tmp/=10;
		}
	return ans;
	}
signed main()
{
vector<int> v;
for(int i=19;i<=20000000;i+=9){
	if(sumdig(i)==10)v.pb(i);
	}
int k;
cin>>k;
cout<<v[k-1];
}