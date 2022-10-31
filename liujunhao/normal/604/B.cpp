#include<cstdio>
#include<algorithm>
#include<queue>
#define MAXN 100000
int n,k,a[MAXN+10],ans;
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
bool check(int mid){
    int i=1,j=n,cnt=0;
    while(i<=j){
        if(a[j]>mid)
            return 0;
        if(a[i]+a[j]>mid)
            j--;
        else
            i++,j--;
            cnt++;
    }
    if(cnt<=k)
        return 1;
    return 0;
}
void partition(int l,int r){
    int mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
}
int main()
{
    Read(n),Read(k);
    for(int i=1;i<=n;i++)
        Read(a[i]);
    partition(1,3000000);
    printf("%d\n",ans);
}