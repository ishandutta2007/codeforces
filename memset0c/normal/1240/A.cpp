#include<bits/stdc++.h>
#define ll long long
#define int long long
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=4e5+10;
int T,n,k,x,y,a,b,l,r,mid,ans,p[N];
bool check(int cur){
	int lcm=a/std::__gcd(a,b)*b,A=cur/a-cur/lcm,B=cur/b-cur/lcm,C=cur/lcm;
	int sum=0;
	for(int i=1;i<=C;i++)sum+=p[i]*(x+y);
	for(int i=C+1;i<=C+A;i++)sum+=p[i]*x;
	for(int i=C+A+1;i<=C+A+B;i++)sum+=p[i]*y;
	// printf("check %lld : %lld %lld %lld : %lld\n",cur,A,B,C,sum);
	return sum>=k;
}
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n);
		for(int i=1;i<=n;i++)read(p[i]),p[i]/=100;
		std::sort(p+1,p+n+1),std::reverse(p+1,p+n+1);
		read(x),read(a),read(y),read(b),read(k);
		if(x<y)std::swap(x,y),std::swap(a,b);
		// print(p,1,n);
		ans=-1,l=1,r=n;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid))r=mid-1,ans=mid;
			else l=mid+1;
		}
		print(ans,'\n');
	}
}