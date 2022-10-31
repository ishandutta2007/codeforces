#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100000
int f[MAXN+10][3],mx[2][2],n;
char s[MAXN+10];
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
    int i;
    Read(n);
    scanf("%s",s+1);
    for(i=1;i<=n;i++)
        s[i]-='0';
    for(i=1;i<=n;i++){
        f[i][0]=mx[s[i]^1][0]+1;
        
        f[i][1]=mx[s[i]][0]+1;
        if(s[i]!=s[i-1])
            f[i][1]=max(f[i][1],f[i-1][1]+1);
        
        f[i][2]=mx[s[i]^1][1]+1;
        mx[s[i]^1][1]=max(f[i][1],mx[s[i]^1][1]);
        mx[s[i]][0]=f[i][0];
        mx[s[i]][1]=max(mx[s[i]][1],f[i][2]);
    }
    printf("%d\n",max(max(mx[0][0],mx[0][1]),max(mx[1][1],mx[1][0])));
}