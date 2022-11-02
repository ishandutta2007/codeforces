#include <bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n;



int main()
{
//    freopen("me.out","w",stdout);
    T=read();
    while(T--)
    //for(n=1;n<=200000;n++)
    {
        n=read();
        int mn=6+10+14+1;

        if(n<mn)puts("NO");
        else{

            if(n==36){
                puts("YES");
                puts("5 6 10 15");
            }
            else if(n==40){
                puts("YES");
                puts("3 6 10 21");
            } else if(n==44){
                puts("YES");
                puts("6 7 10 21");

            } else{
                int x=n-mn+1;
                puts("YES");
                printf("%d %d %d %d\n",x,6,10,14);
                assert(x!=6); assert(x!=10); assert(x!=14);
                assert(x+6+10+14==n);
            }


        }
    }
}