#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 50
bool f1[MAXN+5],f2[MAXN+5];
using namespace std;
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
int n;
int main()
{
    int i,x,y;
    Read(n);
    bool f=0;
    n*=n;
    for(i=1;i<=n;i++){
        Read(x),Read(y);
        if(!f1[x]&&!f2[y]){
            f1[x]=f2[y]=1;
            if(!f)
                f=1;
            else
                printf(" ");
            printf("%d",i);
        }
    }
}