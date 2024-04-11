#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100000
int n,d;
long long ans;
pair<int,int>a[MAXN+10];
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
    int i,j;
    long long cnt=0;
    Read(n),Read(d);
    for(i=1;i<=n;i++)
        Read(a[i].first),Read(a[i].second);
    sort(a+1,a+n+1);
    i=j=1;
    while(j<=n){
        while(j<=n&&a[j].first-a[i].first<d)
            cnt+=a[j++].second;
        ans=max(ans,cnt);
        cnt-=a[i++].second;
        while(i<=n&&a[i].first==a[i-1].first)
            cnt-=a[i++].second;
    }
    printf("%I64d",ans);
}