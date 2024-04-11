#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 4000
void Read(long long &x){
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
long long v[MAXN+10],d[MAXN+10],p[MAXN+10],n,ans,a[MAXN+10];
void del(long long i){
    long long j;
    for(j=i+1;j<=n;j++)
        p[j]-=d[i];
}
bool f[MAXN+10];
int main()
{
    long long i,j;
    Read(n);
    for(i=1;i<=n;i++)
        Read(v[i]),Read(d[i]),Read(p[i]);
    for(i=1;i<=n;i++)
        if(p[i]>=0){
            long long cnt=0;
            a[++ans]=i;
            for(j=i+1;j<=n;j++){
                while(j<=n&&f[j])
                   j++;
                if(j>n||cnt>v[i])
                    break;
                p[j]-=v[i]- ++cnt+1;
            }
            for(j=i+1;j<=n;j++)
                if(p[j]<0&&!f[j])
                    del(j),f[j]=1;
        }
    printf("%I64d\n",ans);
    for(i=1;i<ans;i++)
        printf("%I64d ",a[i]);
    printf("%I64d\n",a[ans]);
}