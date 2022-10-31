#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAXN 100000
#define Log 18
using namespace std;
int n,a[MAXN+10],m,d[MAXN+10],ld[MAXN+10],rd[MAXN+10],s[MAXN+10][20];
long long ans;
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
int main()
{
    int i,l,r,j,k;
    Read(n),Read(m);
    memset(s,0xff,sizeof s);
    for(i=1;i<=n;i++)
        Read(a[i]);
    for(i=1;i<n;i++)
        d[i]=abs(a[i+1]-a[i]);
    n--;
    for(i=2;i<=n;i++){
        s[i][0]=d[i-1];
        k=i;
        for(j=1;j<=Log;j++){
            if(i-(1<<j)<=0)
                break;
            s[i][j]=max(s[i][j-1],s[i-(1<<(j-1))][j-1]);
        }
        for(j=Log;j>=0;j--)
            if(s[k][j]>=0&&s[k][j]<=d[i])
                k=k-(1<<j);
        ld[i]=k-1;
    }
    memset(s,0xff,sizeof s);
    for(i=n;i;i--){
        s[i][0]=d[i+1];
        k=i;
        for(j=1;j<=Log;j++){
            if(i+(1<<j)>n)
                break;
            s[i][j]=max(s[i][j-1],s[i+(1<<(j-1))][j-1]);
        }
        for(j=Log;j>=0;j--)
            if(s[k][j]>=0&&s[k][j]<d[i])
                k=k+(1<<j);
        rd[i]=k+1;
    }
    while(m--){
        Read(l),Read(r);
        r--;
        ans=0;
        for(i=l;i<=r;i++)
            ans+=1ll*(i-max(ld[i],l-1))*(min(rd[i],r+1)-i)*d[i];
        printf("%I64d\n",ans);
    }
}