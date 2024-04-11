#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 1000
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
int n,a[MAXN+10];
int main()
{
    int i,cnt=0,ca=0;
    Read(n);
    for(i=1;i<=n;i++)
        Read(a[i]);
    while(1){
        for(i=1;i<=n;i++)
            if(cnt>=a[i])
                cnt++,a[i]=MAXN+100;
        if(cnt>=n)
            break;
        ca++;
        for(i=n;i;i--)
            if(cnt>=a[i])
                cnt++,a[i]=MAXN+100;
        if(cnt>=n)
            break;
        ca++;
    }
    printf("%d",ca);
}