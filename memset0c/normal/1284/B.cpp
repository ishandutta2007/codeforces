
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
const int N=1e6+10;
int n,min[N],max[N],fl[N],sum[N];
long long ans;
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),memset(min,63,sizeof(min));
	for(int c,i=1;i<=n;i++){
		read(c);
		for(int x,j=1;j<=c;j++){
			read(x);
			if(x>min[i])fl[i]=true;
			max[i]=std::max(max[i],x);
			min[i]=std::min(min[i],x);
		}
	}
	for(int i=1;i<=n;i++)(fl[i]?sum[1000005]:sum[max[i]])++;
	for(int i=1;i<=1000005;i++)sum[i]+=sum[i-1];
	for(int i=1;i<=n;i++)if(fl[i])ans+=n; else ans+=sum[1000005]-sum[min[i]];
	print(ans,'\n');
}