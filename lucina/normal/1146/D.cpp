#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,a,b,g,r,first[maxn];
long long ans;

int main(){
    scanf("%d%d%d",&m,&a,&b);
    g=__gcd(a,b);
    memset(first,-1,sizeof(first));
    int x=0,y=0;
    first[0]=0;
    while(true){
        if(x>=b){
            x-=b;
        }
        else{
            x+=a;
        }
        if(x==0)break;
        y=max(y,x);
        first[x]=y;
    }
    for(int i=0;i<a+b;i++){
        if(first[i]!=-1)
            ans+=max(0,m-first[i]+1);
    }
    /*
    we would like to count how many times each number would be count
    for number <(a+b) it would be count m-(first)+1 times
    if(x>=a+b) first[x]=(x/g+(x%g==0))*g;
    then
    m-first[x]+1
    x+g x+g..... x+g x+2*g x+2*g+..... x+
    m-f[x]+1
    1+2+333
    WTF this is fucking wrong
    we want to count m-x+1 m-(x+g)+1..  m-(x+k*g)+1
    */
    if(m>=a+b){
        r=m-(a+b);
        ans+=(r+1);
        int x1=(r/g);// last number divided by g
        ans+=(1ll*(m+1-a-b)*x1);
        ans-=(1ll*x1*(x1+1)/2*g);
    }
    printf("%lld\n",ans);
}