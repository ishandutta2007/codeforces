//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())    if (ch == '-')  positive = 0;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
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

int T,n,a[1000005],ans;

signed main()
{
    T=read();
    while (T--)
    {
        n=read();ans=0;
        for (int i=1;i<=n;i++) a[i]=read();
        sort(a+1,a+n+1);
        ans=a[n-4]*a[n-3]*a[n-2]*a[n-1]*a[n];
        ans=max(ans,a[1]*a[2]*a[n-2]*a[n-1]*a[n]);
        ans=max(ans,a[1]*a[2]*a[3]*a[4]*a[n]);
        writeln(ans);
    }   
}