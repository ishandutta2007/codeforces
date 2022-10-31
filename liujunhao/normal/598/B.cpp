#include<cstdio>
#define MAXN 10000
int m;
char a[MAXN+10],b[MAXN+10];
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
    int l,r,k,len,i;
    scanf("%s",a+1);
    Read(m);
    while(m--){
        Read(l),Read(r),Read(k);
        len=r-l+1;
        for(i=l;i<=r;i++)
            b[(i-l+k)%len+l]=a[i];
        for(i=l;i<=r;i++)
            a[i]=b[i];
    }
    puts(a+1);
}