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
const int N=4e5+10,M=2e7+1;
int n,a[N],ans;
bool s[M+10];
void add(int x){
	x++;
	for(int i=x;i<=M;i+=i&-i)s[i]^=1;
}
bool ask(int x){
	x++,x=std::min(x,M),x=std::max(x,0);
	bool tmp=false;
	for(int i=x;i;i-=i&-i)tmp^=s[i];
	return tmp;
}
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=30;i>0;i--){
		memset(s,0,sizeof(s));
		bool now=false;
		for(int j=1;j<=n;j++){
			now^=ask(((1<<i)-1)-(a[j]&((1<<i)-1)))^ask((1<<(i-1))-(a[j]&((1<<i)-1))-1);
			now^=ask(((1<<(i+1))-1)-(a[j]&((1<<i)-1)))^ask((1<<(i-1))+(1<<i)-(a[j]&((1<<i)-1))-1);
			add(a[j]&((1<<i)-1));
		}
		ans^=now<<(i-1);
	}
	printf("%d\n",ans);
}