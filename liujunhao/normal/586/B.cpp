#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 50
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
int a[3][MAXN+10],b[MAXN+10],n,m1,m2;
int main()
{
    m1=m2=0x7fffffff;
    int i,j;
    Read(n);
    for(i=1;i<=2;i++)
        for(j=1;j<n;j++)
            Read(a[i][j]);
    for(i=1;i<=n;i++)
        Read(b[i]);
    for(j=2;j<n;j++)
        a[1][j]+=a[1][j-1];
    for(j=n-2;j;j--)
        a[2][j]+=a[2][j+1];
    for(j=1;j<=n;j++){
        if(a[1][j-1]+a[2][j]+b[j]<m1)
            m2=m1,m1=a[1][j-1]+a[2][j]+b[j];
        else if(a[1][j-1]+a[2][j]+b[j]<m2)
            m2=a[1][j-1]+a[2][j]+b[j];
    }
    printf("%d\n",m1+m2);
}