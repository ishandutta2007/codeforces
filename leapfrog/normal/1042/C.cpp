#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename... A>inline void read(T &t,A &...a) {read(t),read(a...);}
int n,a[200005],tz,tf,tl;vector<int>z,f,l;
inline char cmp1(int x,int y) {return a[x]<a[y];}
inline char cmp2(int x,int y) {return a[x]>a[y];}
signed main()
{
	read(n);
	for(int i=1;i<=n;i++) {read(a[i]);if(!a[i]) l.push_back(i);else if(a[i]>0) z.push_back(i);else f.push_back(i);}
	sort(z.begin(),z.end(),cmp2),sort(f.begin(),f.end(),cmp1),n--,tz=z.size()-1,tf=f.size()-1,tl=l.size()-1;
	while(l.size()>1ull) printf("1 %d %d\n",l[tl],l[tl-1]),tl--,l.pop_back(),n--;
	if(n&&(f.size()&1)&&l.size()) printf("1 %d %d\n",f[tf],l[tl]),tf--,f.pop_back(),n--;
	if(n&&l.size()) printf("2 %d\n",l[tl]),tl--,l.pop_back(),n--;
	if(n&&f.size()&1) printf("2 %d\n",f[tf]),tf--,f.pop_back(),n--;
	while(n&&z.size()>1ull) printf("1 %d %d\n",z[tz],z[tz-1]),tz--,z.pop_back(),n--;
	while(n&&f.size()>1ull) printf("1 %d %d\n",f[tf],f[tf-1]),tf--,f.pop_back(),n--;
	if(n&&z.size()&&f.size()) printf("1 %d %d\n",z[tz],f[tf]),n--;
	return 0;
}