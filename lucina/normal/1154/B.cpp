#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int s;bool ok;
    for(int x=0;x<=1000;x++){
        s=a[1]+x;
        ok=true;
        for(int i=2;i<=n;i++){
            ok&=(a[i]==s||a[i]-x==s||(a[i]+x==s));
        }
        if(ok)
            return printf("%d",x),0;
        s=a[1]-x;
        ok=true;
        for(int i=2;i<=n;i++){
            ok&=(a[i]==s||a[i]-x==s||(a[i]+x==s));
        }
        if(ok)
            return printf("%d",x),0;
        s=a[1];
        ok=true;
        for(int i=2;i<=n;i++){
            ok&=(a[i]==s||a[i]-x==s||(a[i]+x==s));
        }
        if(ok)
            return printf("%d",x),0;
    }
    printf("-1");
}