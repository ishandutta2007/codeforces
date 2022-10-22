#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
int t;
int n,k;
int x[maxn];
int y[maxn];
bool fr[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        scanf("%d",&k);
        for(int i=1;i<=k;i++) scanf("%d %d",&x[i],&y[i]);
        for(int i=1;i<=2*n;i++) fr[i]=true;
        for(int i=1;i<=k;i++) {
            fr[x[i]]=false;
            fr[y[i]]=false;
        }
        if(k<n) {
            int p=1;
            while(!fr[p]) p++;
            int q=p;
            int l=n-k;
            while(l>0) {
                q++;
                if(fr[q]) l--;
            }
            x[k+1]=p;
            y[k+1]=q;
            fr[p]=fr[q]=false;
            for(int i=k+2;i<=n;i++) {
                while(!fr[p]) p++;
                while(!fr[q]) q++;
                fr[p]=false;
                fr[q]=false;
                x[i]=p;
                y[i]=q;
            }
        }
        for(int i=1;i<=n;i++) if(x[i]>y[i]) swap(x[i],y[i]);
        int ans=0;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                ans++;
                if(x[i]<x[j] && y[j]<y[i]) ans--;
                if(x[j]<x[i] && y[i]<y[j]) ans--;
                if(y[j]<x[i] || y[i]<x[j]) ans--;
            }
        }
        printf("%d\n",ans);
    }
}