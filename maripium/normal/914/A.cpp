#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
bool pq(int x){
	if(x<0)return 0;
	return floor(sqrt(x))==sqrt(x);
	}
signed main()
{
int n,a[1005];
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
for(int i=n-1;i>=0;i--){
	if(!pq(a[i])){cout<<a[i];return 0;}
	}
}