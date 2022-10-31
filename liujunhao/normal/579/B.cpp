#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 800
int n,cnt[MAXN+10],ans,p[MAXN+10];
bool f[MAXN+10];
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
struct node{
    int s,pos;
    bool operator<(const node &x)const{
        if(s==x.pos)
            return pos>x.pos;
        return s>x.s;
    }
}a[ MAXN+10][MAXN+10];
int main()
{
    Read(n);
    n*=2;
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<i;j++){
            Read(a[i][j].s);
            a[i][j].pos=j;
            a[j][i].s=a[i][j].s;
            a[j][i].pos=i;
    }
    for(i=1;i<=n;i++){
        sort(a[i]+1,a[i]+n+1);
        cnt[i]=1;
    }
    while(ans<n)
        for(i=1;i<=n;i++){
            if(f[i])
                continue;
            while(f[a[i][cnt[i]].pos])
                cnt[i]++;
            p[i]=a[i][cnt[i]].pos;
            if(p[i]<i&&p[p[i]]==i)
                f[i]=f[p[i]]=1,ans+=2;
        }
    for(i=1;i<n;i++)
        printf("%d ",p[i]);
    printf("%d\n",p[n]);
}