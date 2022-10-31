#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 200000
#define MOD 1000000007
int cnt[MAXN+10],n,a,fac;
void Read(int &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
int quick_pow(int a,int b){
    int t=1;
    while(b){
        if(b&1)
            t=(1ll*t*a)%MOD;
        a=1ll*a*a%MOD;
        b>>=1;
    }
    return t;
}
int main()
{
    a=fac=1;
    int i,t;
    bool f=0;
    Read(n);
    for(i=1;i<=n;i++){
        Read(t);
        cnt[t]++;
        a=1ll*a*t%MOD;
    }
    for(i=1;i<=MAXN;i++)
        if(cnt[i]&1){
            f=1;
            break;
        }
    if(f){
        for(i=1;i<=MAXN;i++)
            if((cnt[i]&1)&&f){
                f=0,fac=1ll*fac*((cnt[i]+1)/2)%(MOD-1);
            }
            else{
                fac=1ll*fac*(cnt[i]+1)%(MOD-1);
            }
        printf("%d\n",quick_pow(a,fac));
    }
    else{
        a=1;
        for(i=1;i<=MAXN;i++){
            fac=1ll*fac*(cnt[i]+1)%(MOD-1);
            a=1ll*a*quick_pow(i,cnt[i]/2)%MOD;
        }
        printf("%d\n",quick_pow(a,fac));
    }
}