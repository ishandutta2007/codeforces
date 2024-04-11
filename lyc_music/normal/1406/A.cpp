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

int n,ans,a[101],T,x;

signed main()
{
    T=read();
    while (T--)
    {
        n=read();ans=0;
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            x=read();
            a[x]++;
        }
        for (int i=0;i<=101;i++)
          if (!a[i])
          {
            ans+=i;
            break;
          }
        for (int i=0;i<=101;i++)
          if (1>=a[i])
          {
            ans+=i;
            break;
          }
        writeln(ans);
    }
}