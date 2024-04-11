//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 1000005
#define int long long

using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())    if (ch == '-')  positive = 0;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if (a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    printf("%d\n",a/2);
}
void Print(int x)
{
    if (x&1) x++;
    write(x/2);
}
int n,a[N],s[N],ans,m,x,y,z,ans1,ans2;

void doint(int l,int x)
{
    l--;
    if (l==0) ans1+=x;
    if (l<1||n<=l) return;
    if (a[l]>0) ans2-=a[l];
    a[l]+=x;
    if (a[l]>0) ans2+=a[l];
}

signed main()
{
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    ans1=a[1];
    for (int i=1;i<=n;i++) a[i]=a[i+1]-a[i];
    for (int i=1;i<n;i++) if (a[i]>0) ans2+=a[i];
    Print(ans1+ans2);
        printf("\n");
    m=read();
    for (int i=1;i<=m;i++)
    {
        x=read(),y=read(),z=read();
        doint(x,z);
        doint(y+1,-z);
        Print(ans1+ans2);printf("\n");
    }
}