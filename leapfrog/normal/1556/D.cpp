#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
#define int long long
int n,K,rs[1000005],sm[1000005];
signed main()
{
	read(n,K);for(int i=2;i<=n;i++)
	{
		cout<<"or "<<1<<" "<<i<<endl;
		int a;read(a);
		cout<<"and "<<1<<" "<<i<<endl;
		int b;read(b),sm[i]=a+b;
	}
	cout<<"or "<<2<<" "<<3<<endl;
	int a;read(a);
	cout<<"and "<<2<<" "<<3<<endl;
	int b;read(b);int sum=a+b;
	rs[1]=(sm[2]+sm[3]-sum)/2;
	for(int i=2;i<=n;i++) rs[i]=sm[i]-rs[1];
	sort(rs+1,rs+n+1);
	cout<<"finish "<<rs[K]<<endl;
	return 0;
}