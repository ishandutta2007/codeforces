#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 500000
int n,a[MAXN+10],ans,cnt;
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
    int i,j,k;
    Read(n);
    for(i=1;i<=n;i++)
        Read(a[i]);
    a[0]=a[1],a[n+1]=a[n];
    for(i=1;i<n;i++){
        j=i;
        while(a[j]!=a[j+1]&&a[j]!=a[j-1])
            j++;
        if(j==i)
            continue;
        ans=max(ans,j-i);
        if(a[i-1]==a[j]){
            for(;i<j;i++)
                a[i]=a[i-1];
            i--;
        }
        else{
            k=j;
            for(j--;i<j;i++,j--)
                a[i]=a[i-1],a[j]=a[j+1];
            i=k-1;
        }
    }
    printf("%d\n",(ans+1)/2);
    for(i=1;i<n;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);
}