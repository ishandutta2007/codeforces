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
int n;char ch;string a,b;
inline void solve(int x)
{
	if(x==1) return ch='A',a="",b="A",void();
	if(x==2) return ch='B',a="B",b="AB",void();
	if(x&1) solve(x>>1),ch++,a=a+ch+ch,b=b+ch;
	else solve((x-1)>>1),ch++,a=ch+a+ch+ch,b=b+ch;
}
int main() {read(n),solve(n),cout<<b+a<<" "<<b<<endl;}