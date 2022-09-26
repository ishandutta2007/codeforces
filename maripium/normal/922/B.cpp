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
const int N=1005;
const double pi=acos(-1);
int n;
signed main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int k=i^j;
			if( k<=n && k>=j && i+j>k)++ans;
			}
		}
	cout<<ans;	
}