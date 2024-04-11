#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
priority_queue<int> points;
int n;
int a[maxn];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        a[i]-=i;
    }
    long long ans=0;
    points.push(a[0]);
    for(int i=1;i<n;i++) {
        if(points.top()>a[i]) {
            ans+=(points.top()-a[i]);
            points.pop();
            points.push(a[i]);
        }
        points.push(a[i]);
    }
    printf("\n %lld",ans);
    return 0;
}