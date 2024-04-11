#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int pt=1;
    for(int i=1;i<=n;i++){
        while(a[pt]<i&&pt<n)
            pt++;
        if(a[pt]<i)return printf("%d\n",ans),0;
        pt++;ans++;
    }
    printf("%d\n",ans);

}