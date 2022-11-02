#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
char s[N];
char h[N];
char t[]=" abacaba";
int T;

int main()
{
//    freopen("data.in","r",stdin);

    T=read();

    while(T--){
        n=read();
        scanf("%s",s+1);
        bool ook=0;
        for(int i=1;i+7-1<=n;i++)
        {
            bool ok=1;
            for(int j=1;j<=n;j++) h[j]=s[j];
            for(int j=1;j<=7;j++)
            {
                if(h[i+j-1]=='?') h[i+j-1]=t[j];

                if(h[i+j-1]!=t[j])
                {
                    ok=0; break ;
                }
            }
        //    cerr<<i
            if(!ok) continue ;

            if(ok)
            {
                bool find=0;
                for(int j=1;j+7-1<=n;j++)
                if(j!=i)
                {
                    bool nok=1;
                    for(int k=1;k<=7;k++)
                    {
                        if(h[j+k-1]!=t[k])
                        {
                            nok=0; break ;
                        }
                    }
                    if(nok) find=1;
                    if(find) break ;
                }
                if(!find) ook=1;
            }

            if(ook)
            {
                puts("Yes");
                for(int j=1;j<=n;j++)
                {
                    if(h[j]=='?') h[j]='z';
                    putchar(h[j]);
                }
                puts("");
                break ;
            }
        }
        if(!ook) puts("No");
    }
}