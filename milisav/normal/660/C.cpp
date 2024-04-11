#include<bits/stdc++.h>
using namespace std;
int ans=0;
int a[400000];
int n,k;
int pa,qa;
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    pa=0;
    qa=-1;
    int p=0;
    int q=-1;
    int cnt=0;
    while(p<n) {
        while(q+1<n && cnt+(1-a[q+1])<=k) {
            q++;
            cnt+=(1-a[q]);
        }
        if(q-p+1>ans) {
            ans=q-p+1;
            pa=p;
            qa=q;
        }
        cnt-=(1-a[p]);
        p++;

    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++) {
        if(i>=pa && i<=qa) printf("1 ");
        else printf("%d ",a[i]);
    }
    return 0;
}