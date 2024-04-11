#include<bits/stdc++.h>
#define int long long
using namespace std;
int a;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c))f=(c==45?-f:f),c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
} 
inline void write(int x){
	if(x<0)putchar(45),x=-x;
	if(x<10){putchar(x|48);return;}
	write(x/10);putchar((x%10)|48);
}
signed main(){
	a=read();
	write(a-1000000000000000000ll%a*9%a*9%a);putchar(32);
	write(1000000000000000000ll+a-1000000000000000000ll%a*9%a*9%a-1);
}