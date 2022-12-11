#include<bits/stdc++.h>
#define i64 long long
using namespace std;
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
i64 solve(i64 n,i64 k){
	function<i64(i64)> locate=[&](i64 m){return (m-1)/(k*k+1);};
	function<pair<i64,i64>(i64)> getkey=[&](i64 i){
		if(!i)return make_pair(k*(k+1)/2,k);
		i64 j=i/k,t=i%k,oldkey=getkey(j).first;
		i64 l=j*(k*k+1)+t*k+1,r=j*(k*k+1)+(t+1)*k,offset=0;
		if(oldkey<=l)offset=k;
		else if(l<=oldkey&&oldkey<=r)offset=r-oldkey+1;
		return make_pair((l+r)*k/2+offset,r+(offset?1:0));
	};
	function<i64(i64)> calc=[&](i64 n){
		i64 i=locate(n),key=getkey(i).first;
		assert(key!=n),n-=key<n;
		i64 t=(n-i*(k*k+1)-1)/k,p=(n-i*(k*k+1)-1)%k+1;
		// printf("t=%lld p=%lld\n",t,p);
		return (i*k+t)*(k+1)+p;
	};
	i64 i=locate(n),key,from;
	tie(key,from)=getkey(i);
	// printf("solve(%lld,%lld) i=%lld key=%lld from=%lld\n",n,k,i,key,from);
	return key==n?calc(from)+1:calc(n);
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	int T,k; i64 n;
	for(read(T);T--;)read(n),read(k),print(solve(n,k),'\n');
}