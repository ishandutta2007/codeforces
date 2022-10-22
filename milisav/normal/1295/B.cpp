#include<bits/stdc++.h>
using namespace std;
char s[3000000];
int c[3000000];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,x;
        scanf("%d %d",&n,&x);
        scanf("%s",s);
        int b=0;
        c[n+b]++;
        for(int i=0;i<n;i++) {
            if(s[i]=='0') b++;
            else b--;
            if(i!=n-1) {
                c[n+b]++;
            }
        }
        int ans=0;
        for(int i=0;i<=2*n;i++) {
            int t=i-n;
            if(b==0) {
                if(x==t && c[i]!=0) {
                    ans=-1;
                    break;
                }
            }
            else {
                if((x-t)%b==0 && (x-t)/b>=0) {
                    //cout<<t<<" "<<x<<" "<<b<<" "<<i<<" "<<c[i]<<endl;
                    ans+=c[i];
                }
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<=2*n;i++) c[i]=0;
    }
    return 0;
}