#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int tot;
int t;
int n,m,k;
int b[maxn];
int cnt[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d",&n,&k,&m);
        bool ok=false;
        for(int i=1;i<=n;i++) {
            cnt[i]=0;
        }
        for(int i=0;i<m;i++) {
            scanf("%d",&b[i]);
            cnt[b[i]]=1;
        }
        tot=n-m;
        if(tot%(k-1)!=0) {
            printf("NO\n");
        }
        else {
            int cur=0;
            ok=false;
            //cout<<"?"<<endl;
            for(int i=1;i<=n;i++) {
                if(cnt[i]==0) cur++;
                else {
                    //cout<<i<<" "<<cur<<" "<<tot-cur<<endl;
                    if(cur>=k/2 && (tot-cur)>=k/2) {
                        ok=true;
                        break;
                    }
                }
            }
            if(ok) {
                printf("YES\n");
            }
            else  {
                printf("NO\n");
            }
        }
    }
    return 0;
}