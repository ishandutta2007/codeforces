//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
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
using namespace std;
int T,n,k,val[100005],sum;
bool bl;
bool che()
{
    for(int i=1;i<=n;++i)
    {
        if(val[i]!=k)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    T=read();
    while(T--)
    {
        n=read(),k=read();
        sum=0;
        bl=0;
        for(int i=1;i<=n;++i)
        {
            val[i]=read();
            if(val[i]==k)bl=1;
        }
        for (int i=1;i<=n;i++) 
            sum+=val[i];
        if(che())
        {
        	writeln(0);
            continue;
        }
        if(bl||sum==k*n)
        {
        	writeln(1);
            continue;
        }
        writeln(2);
    }
}