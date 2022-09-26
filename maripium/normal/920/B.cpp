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
int n,l[N],r[N];
signed main()
{
int test;
cin>>test;
while(test--)
{
	cin>>n;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
    int cur=1;
    for(int i=1;i<=n;++i){
    	if(cur>r[i])cout<<0<<sp;
    	else cout<<max(cur,l[i])<<sp,cur=max(l[i],cur)+1;
    	}
    cout<<endl;
}
}