#include<bits/stdc++.h>
#define FL fflush(stdout)
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
const int N=2e5+10;
int T,n,a[N],min,pos;
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		min=INT_MAX,read(n);
		for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<=n;i++){
			if(a[i]-i>=min){
				printf("Yes\n%d %d\n",pos,i);
				goto finish;
			}
			if (min>a[i]-i+1)min=a[i]-i+1,pos=i;
		}
		min=INT_MAX,std::reverse(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]-i>=min){
				printf("Yes\n%d %d\n",n+1-i,n+1-pos);
				goto finish;
			}
			if(min>a[i]-i+1)min=a[i]-i+1,pos=i;
		}
		puts("No");
		finish:;
	}
}