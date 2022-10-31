#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100000
int n,a[MAXN+10],ans;
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
    Read(n);
    int i,cnt=0;
    for(i=1;i<=n;i++){
        Read(a[i]);
        if(a[i]>=a[i-1])
            cnt++;
        else
            cnt=1;
        ans=max(ans,cnt);
    }
    printf("%d",ans);
}