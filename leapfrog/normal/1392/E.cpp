//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int main()
{
	int n,T;read(n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cout<<((i&1ll)<<(i+j-1)),j==n-1?cout<<endl:cout<<' ';
	for(read(T);T--;)
	{
		ll x;read(x),cout<<"1 1"<<endl;int i=0,j=0;
		for(;i<n-1||j<n-1;cout<<i+1<<" "<<j+1<<endl) {char f=(x>>(i+j))&1;((i&1)==f?j:i)++;}
	}
	return 0;
}