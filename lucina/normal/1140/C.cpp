#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k;
struct pa{
int t,b;
bool operator<(const pa x)const{
    return b>x.b;
}
}a[maxn];
priority_queue<int> q;
long long ans,sum;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].t,&a[i].b);
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,(long long)a[i].t*a[i].b);
        }
        printf("%lld\n",ans);
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        ans=max(ans,(long long)a[i].b*(a[i].t+sum));
        if(q.size()<k-1){
            q.push(-a[i].t);
            sum+=a[i].t;
        }
        else{
            if(-q.top()<a[i].t){
                sum+=q.top(); sum+=a[i].t;
                q.pop();q.push(-a[i].t);
            }
        }
    }
    printf("%lld\n",ans);
}