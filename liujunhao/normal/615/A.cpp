#include<cstdio>
#define MAXN 100
bool f[MAXN+10];
int n,m,na,a,cnt;
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
    Read(m),Read(n);
    int i,j;
    for(i=1;i<=m;i++){
        Read(na);
        for(j=1;j<=na;j++){
            Read(a);
            if(!f[a])
                f[a]=1,cnt++;
        }
    }
    if(cnt==n)
        puts("YES");
    else
        puts("NO");
}