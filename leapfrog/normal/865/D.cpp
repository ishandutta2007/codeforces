//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n;priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	read(n);long long pr=0;
	for(int i=1,x;i<=n;i++) {read(x);if(!q.empty()&&x>q.top()) pr+=x-q.top(),q.pop(),q.push(x);q.push(x);}
	return printf("%lld\n",pr),0;
}