#include<bits/stdc++.h>
using namespace std;
int num[500000];
bool brk[500000];
bool ex[500000];
int fg[500000];
int n;
int main() {
    int q;
    scanf("%d",&q);
    while(q--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&num[i]);
            ex[num[i]]=true;
        }
        fg[n+1]=n+1;
        int ans=0;
        for(int i=n;i>=0;i--) {
            fg[i]=fg[i+1];
            if(ex[i+1]) {
                fg[i]=i+1;
                ans++;
            }
        }
        ans--;
        for(int i=0;i<=n;i++) ex[i]=false;
        int mc=0;
        int tmc=0;
        for(int i=0;i<n;i++) {
            if(ex[fg[num[i]]]) brk[num[i]]=true;
            ex[num[i]]=true;
        }
        for(int i=0;i<=n;i++) {
            if(ex[i] && fg[i]!=n+1) {
                if(!brk[i]) tmc++;
                else {
                    mc=max(mc,tmc);
                    tmc=0;
                }
            }
        }
        mc=max(mc,tmc);
        for(int i=0;i<=n+1;i++) {
            ex[i]=brk[i]=false;
            fg[i]=0;
        }
        printf("%d\n",ans-mc);
    }
    return 0;
}