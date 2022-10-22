#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int t;
int n;
int a[maxn];
int b[maxn];
int cnt[2];
pair<int,int> d[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        cnt[0]=cnt[1]=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&b[i]);
        }
        if(cnt[0]==cnt[1]) {
            sort(b,b+n);
            long long ans=0;
            for(int i=0;i<n;i++) {
                ans+=b[i];
                if(i>0) ans+=b[i];
            }
            printf("%lld\n",ans);
        }
        else {
            if(cnt[1]>cnt[0]) {
                for(int i=0;i<n;i++) a[i]=1-a[i];
                swap(cnt[1],cnt[0]);
            }
            for(int i=0;i<n;i++) {
                d[i]={b[i],a[i]};
            }
            sort(d,d+n);
            reverse(d,d+n);
            int k=0;
            long long ans=0;
            for(int i=0;i<n;i++) {
                ans+=d[i].first;
                if(d[i].second==1) ans+=d[i].first;
                else {
                    k++;
                    if(k<=cnt[1]) ans+=d[i].first;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}