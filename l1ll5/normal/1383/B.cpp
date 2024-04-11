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
int n;
int a[N];
int bin[35];
void solve(){
    n=read();
    int sum=0;
    for(int i=1;i<=n;i++) a[i]=read(),sum^=a[i];

    if(sum==0){
        puts("DRAW");
        return ;
    }
    int x=30;


    while(x>=0){
        if((sum>>x)==1){

            int cnt=0;
            for(int i=1;i<=n;i++)
            if(a[i]&bin[x]){
                cnt++;
            }


            int el=n-cnt;
        //    cerr<<cnt<<' '<<el<<endl;

            int win=((cnt%4)==1);


            if(el & 1) {
                if(win==0) win=1;
            }

            if(win) puts("WIN");
            else puts("LOSE");
            return ;
        }
        x--;
    }
}
int main()
{
    bin[0]=1;
    for(int i=1;i<=30;i++) bin[i]=bin[i-1]<<1;
    //freopen("big_zero.in","r",stdin);
    int T;
    T=read();
    while(T--) solve();
}