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
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=1e5+10;
int T,n,a[N];
long long val,sum,_val,_sum;
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n);
		val=sum=0;
		for(int i=1;i<=n;i++)read(a[i]),val^=a[i],sum+=a[i];
		sum+=val;
		printf("2\n%lld %lld\n",val,sum);
		// _val=val^sum,_sum=val+sum;
		// for(int i=1;i<=n;i++)_val^=a[i],_sum+=a[i];
		// printf("%lld %lld\n",_val,_sum);
	}
}