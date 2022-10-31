#include<cstdio>
void Read(int &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>= '0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
int n,ans;
int main()
{
    Read(n);
    while(n){
        ans+=n&1;
        n>>=1;
    }
    printf("%d\n",ans);
}