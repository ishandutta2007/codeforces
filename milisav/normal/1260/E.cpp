#include<bits/stdc++.h>
using namespace std;
int n;
int a[500000];
priority_queue<int> choose;
int r=0;
long long ans;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        if(a[i]==-1) r=n-1-i;
    }
    choose.push(-a[n-1]);
    int t=n/2;
    int i=n-2;
    while(r>0) {
        ans-=choose.top();
        choose.pop();
        int p=t;
        for(;i>=0 && p>0;i--,p--) {
            if(a[i]!=-1) choose.push(-a[i]);
            //else break;
        }
        r-=t;
        t/=2;
    }
    printf("%lld",ans);
    return 0;
}