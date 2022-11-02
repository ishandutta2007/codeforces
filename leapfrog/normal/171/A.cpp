//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
#include<sstream>
int main()
{
	stringstream s,t;
	string a,b;int A,B;
	cin>>a>>b,reverse(b.begin(),b.end());
	s<<a,s>>A,t<<b,t>>B;
	printf("%d\n",A+B);
}