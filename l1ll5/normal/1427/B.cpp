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
int n,k,m;
char s[N];
int a[N];
int main()
{
    //freopen("1.in","r",stdin);
    T=read();
    while(T--){
        n=read(),k=read();
        m=0;
        scanf("%s",s+1);

        int soc=0;
        int lst=0;
        int fi=0;
        int bfi=0;

        int l=1,r=n;


        for(int i=1;i<=n;i++){
            if(s[i]=='L') {
                lst++;
            } else {

                if(s[i-1]=='W') soc+=2;
                else {
                    soc++;

                    if(!bfi) fi=lst,bfi=1;
                    else {
                        if(lst)
                        a[++m]=lst;
                    }
                    lst=0;
                }
            }
        }

        if(lst){
            fi+=lst;
        }

        if(fi==n){
            printf("%d\n",max(0,2*k-1));
            continue ;
        }


        sort(a+1,a+m+1);



        for(int i=1;i<=m;i++){
        //    cerr<<k<<' '<<soc<<' '<<a[i]<<endl;
            if(k>=a[i]){
                k-=a[i];
                soc+=a[i]*2;
                soc++;
            } else {
                soc+=k*2;
                k=0;
                break ;
            }
        }
        if(k){
            int t=min(k,fi);
            soc+=t*2;
        }

        printf("%d\n",soc);
    }
}