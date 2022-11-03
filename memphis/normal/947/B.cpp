#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=100005;

int n,v[N],m[N];
multiset<long long> s;

int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",v+i);
    rep(i,1,n) scanf("%d",m+i);
    long long cnt=0;
    rep(i,1,n){
        s.insert(v[i]+cnt);
        cnt+=m[i];
        long long ans=0;
        while(!s.empty() && (*s.begin()<=cnt)){
            ans+=(*s.begin()-cnt+m[i]);
            s.erase(s.begin());
        }
        ans+=(long long)s.size()*m[i];
        printf("%I64d ",ans);
    }
}