# include <stdio.h>
# include <string.h>
int min(int i,int j){return i<j?i:j;}
char a[201], b[201];
int c[10], d[10];
int n,m,i,j;

int main()
{
    scanf("%s",a); n=strlen(a);
    scanf("%s",b); m=strlen(b);
    for(i=0; i<n; i++) c[a[i]-'0']++;
    for(i=0; i<m; i++) d[b[i]-'0']++;
    c[2]=c[5]=c[2]+c[5];
    c[6]=c[9]=c[6]+c[9];
    d[2]=d[5]=d[2]+d[5];
    d[6]=d[9]=d[6]+d[9];
    int ans = m;
    for(i=0; i<10; i++) if(c[i])
        ans = min(ans, d[i]/c[i]);
    printf("%d\n",ans);
    return 0;
}