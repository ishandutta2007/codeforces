#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T x,int l,int r){for(int i=l;i<=r;i++)print(x[i]," \n"[i==r]);}
const int N=1e6+10;
int n,a[N];
long long ans[2];
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++){
		ans[i&1]+=a[i]>>1;
		ans[i&1^1]+=(a[i]+1)>>1;
	}
	print(std::min(ans[0],ans[1]),'\n');
}