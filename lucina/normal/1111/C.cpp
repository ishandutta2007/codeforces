#include<bits/stdc++.h>
using namespace std;
long long n,k,a,b,u,e;
vector<long long> f;

long long p(long long l,long long r){
    long long u=lower_bound(f.begin(),f.end(),l)-f.begin();
    long long v=upper_bound(f.begin(),f.end(),r)-f.begin();
    long long x=v-u;
    long long p1;
    if(x==0)
        p1=a;
    else
        p1=x*(b)*(r-l+1);
    long long mid=(l+r)>>1;
    if(x==0||l==r){
        return p1;
    }
    else
        return min(p1,p(l,mid)+p(mid+1,r));
}
int main(){
    scanf("%lld%lld%lld%lld",&n,&k,&a,&b);
    for(int i=1;i<=k;i++){
        scanf("%lld",&e);
        f.push_back(e);
    }
    sort(f.begin(),f.end());
    long long fuck=(1<<n);
    printf("%lld\n",p((long long)1,fuck));


}