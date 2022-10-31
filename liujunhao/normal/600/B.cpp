#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 200000
int a[MAXN+10],b[MAXN+10],n,m;
void Read(int &x){
    char c;
    bool f=0;
    while(c=getchar(),c!=EOF){
        if(c=='-')
            f=1;
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            if(f)
                x=-x;
            return;
        }
    }
}
int main()
{
    int i;
    Read(n),Read(m);
    for(i=1;i<=n;i++)
        Read(a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<=m;i++){
        Read(b[i]);
        b[i]=upper_bound(a+1,a+n+1,b[i])-a-1;
    }
    for(i=1;i<m;i++)
        printf("%d ",b[i]);
    printf("%d\n",b[m]);
}