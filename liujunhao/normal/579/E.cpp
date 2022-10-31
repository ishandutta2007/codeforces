#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 200000
int a[MAXN+10],n;
double l[MAXN+10];
void Read(int &x){
    char c;
    bool f=0;
    while(c=getchar(),c!=EOF){
        if(c=='-')
            f=1;
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            if(f)
                x=-x;
            ungetc(c,stdin);
            return;
        }
    }
}
double get_poor(double x){
    int i;
    double sum=0,ret=0;
    for(i=1;i<=n;i++)
        l[i]=a[i]-x;
    for(i=1;i<=n;i++){
        sum+=l[i];
        if(sum<0)
            sum=0;
        ret=max(sum,ret);
        l[i]=-l[i];
    }
    sum=0;
    for(i=1;i<=n;i++){
        sum+=l[i];
        if(sum<0)
            sum=0;
        ret=max(sum,ret);
    }
    return ret;
}
int main()
{
    Read(n);
    int i;
    for(i=1;i<=n;i++)
        Read(a[i]);
    double l=-1e4,r=1e4,m1,m2,v1,v2;
    i=100;
    while(i--){
        m1=l+(r-l)/3;
        m2=m1+(r-m1)/2;
        v1=get_poor(m1);
        v2=get_poor(m2);
        if(v1>v2)
            l=m1;
        else
            r=m2;
    }
    printf("%.15lf\n",get_poor(l));
}