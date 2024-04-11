#include<cstdio>
int n,b;
long long x,y;
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
    int i,a;
    Read(n),Read(b);
    for(i=1;i<=n;i++)
        Read(a),x=x*b+a;
    Read(n),Read(b);
    for(i=1;i<=n;i++)
        Read(a),y=y*b+a;
    if(x>y)
        putchar('>');
    else if(x<y)
        putchar('<');
    else
        putchar('=');
}