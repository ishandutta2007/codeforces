#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL
const int mod=12*3600;
int main(){
    int h,m,s,t1,t2,k,l;
    scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
    if(h==12) h=0;
    if(t2==12) t2=0;
    if(t1==12) t1=0;
    int a[]={h*3600+m*60+s,m*720+12*s,s*720};
    sort(a,a+3);
    int itr=0;
    t1*=3600,t2*=3600;
    while(itr  < 3 && a[itr]<t1 ) itr++;
    if(itr==3) itr=0;
    k=(t2-t1+mod)%mod,l=(a[itr]-t1+mod)%mod;
    if(k<l){
        printf("YES");
        return 0;
    }
    k=mod-k;
    itr=2;
    while(itr >= 0 && a[itr]>t1) itr--;
    if(itr==-1) itr=2;
    l=(t1-a[itr]+mod)%mod;
    if(k<l){
        printf("YES");
        return 0;
    }
    printf("NO");
 
}