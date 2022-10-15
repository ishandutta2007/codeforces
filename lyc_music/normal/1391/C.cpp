//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
int fac[1000005],n,mo=1e9+7;
int miyun(int x, int y)
{
	int kkk = 1, tt = x;
	while(y > 0)
    {
		if(y%2==1)
			(kkk*=tt)%=mo;
        (tt*=tt)%=mo;
		y>>=1;
	}
	return kkk;
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<=1000005;i++) fac[i]=fac[i-1]*i%mo;
	n=read();
	writeln((fac[n]-miyun(2,n-1)+mo)%mo);
}