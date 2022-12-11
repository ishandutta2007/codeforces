#include<bits/stdc++.h>
#define ll long long 
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
const int N=1e5+10,mod=998244353;
int T;
ll n;
bool solve(ll x){
	if(x%7==0)return false;
	x=x-x%7;
	if((x/7)<2)return false;
	if((x/7)%2!=0)return false;
	return true;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n);
		puts(solve(n)?"YES":"NO");
	}
}