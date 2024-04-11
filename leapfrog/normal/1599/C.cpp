//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
inline double C1(double x) {return x;}
inline double C2(double x) {return x*(x-1)/2;}
inline double C3(double x) {return x*(x-1)*(x-2)/6;}
int n;double p;
inline double get(double x) {return C3(x)+C1(n-x)*C2(x)+C2(n-x)*C1(x)/2;}
int main()
{
	read(n),scanf("%lf",&p);
	for(int i=0;i<=n;i++) if(get(i)>=p*C3(n)) return printf("%d\n",i),0;
}