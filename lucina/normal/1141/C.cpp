#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],p[1];
long long sum,ma;
bool ch[maxn];

int main(){
    scanf("%d",&n);
    ma=-1e18;
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        sum+=(a[i]);
        ma=max(ma,sum);
    }
    p[1]=ma<0?n:n-ma;
    if(p[1]<1||p[1]>n) return printf("-1"),0;
    ch[p[1]]=true;
    for(int i=2;i<=n;i++){
        p[i]=a[i-1]+p[i-1];
        if(p[i]<1||p[i]>n)
            return printf("-1"),0;
        if(ch[p[i]]) return printf("-1"),0;
        ch[p[i]]=true;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",p[i]);
}