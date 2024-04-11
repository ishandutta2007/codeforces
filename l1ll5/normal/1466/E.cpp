#include <bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
#define int long long
#define mod 1000000007
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n;
int x[N];
long long bit1[62];
long long bin[60];
main()
{
    bin[0]=1;
    for(int i=1;i<60;i++) bin[i]=(bin[i-1]<<1ll)%mod;
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++) x[i]=read();
        for(int i=0;i<=60;i++) bit1[i]=0;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=60;j++)
            if( (x[i]>>j) & 1 ) {
                bit1[j]++;
            }
        }
        //for(int i=0;i<=8;i++) cout<<bit1[i]<<endl;

        long long tans=0;
        for(int i=1;i<=n;i++) {
            long long xj=x[i];
            long long ans1=0;
            for(int j=0;j<60;j++)
            if( (xj>>j) & 1 )
            ans1+=bin[j]*bit1[j]%mod,ans1%=mod;
            long long ans2=0;
            for(int j=0;j<60;j++)
            if( (xj>>j) & 1) {
                ans2+=n*bin[j]%mod;
                ans2%=mod;
            }
            else {
                ans2+=bit1[j]*bin[j]%mod;
                ans2%=mod;
            }
    //        cerr<<ans1<<' '<<ans2<<endl;
            long long rans=ans1*ans2%mod;
            tans+=rans;
            tans%=mod;
        }

        printf("%lld\n",tans);
    }
}