#include<bits/stdc++.h>
#define maxn 1050
using namespace std;
int tc;
int n,k;
char s[maxn][maxn];
char t[maxn][maxn];
int cur[2*maxn];
int sz[2*maxn];
int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d %d",&n,&k);
        bool ok=true;
        for(int i=0;i<n;i++) {
            scanf("%s",s[i]);
            for(int j=0;j<n;j++) t[i][j]='1';
            t[i][n]=0;
        }
        for(int i=-(n-1);i<=n-1;i++) {
            cur[maxn+i]=0;
            sz[maxn+i]=n-abs(i);
        }
        for(int z=0;z<n-k+1 && ok;z++) {
            while(cur[maxn]<n && s[cur[maxn]][cur[maxn]]=='0') cur[maxn]++;
            if(cur[maxn]<n) {
                t[cur[maxn]][cur[maxn]]='0';
                //cout<<z<<" "<<cur[maxn]<<" "<<cur[maxn]<<endl;
                if(z>=0) {
                    cur[maxn+1]=max(cur[maxn+1],cur[maxn]);
                    cur[maxn-1]=max(cur[maxn-1],cur[maxn]);
                    for(int x=1;x<=n-k-z && ok;x++) {
                        int fi=x;
                        int fj=0;
                        if(x!=1) cur[maxn+x]=max(cur[maxn+x],cur[maxn+x-1]);
                        //cout<<z<<" + "<<x<<" "<<fi+cur[maxn+x]<<" "<<fj+cur[maxn+x]<<endl;
                        while(fi+cur[maxn+x]<n && s[fi+cur[maxn+x]][fj+cur[maxn+x]]=='0') cur[maxn+x]++;
                        if(fi+cur[maxn+x]<n) {
                            t[fi+cur[maxn+x]][fj+cur[maxn+x]]='0';
                            cur[maxn+x-1]=max(cur[maxn+x-1],cur[maxn+x]+1);
                        }
                        else {
                            ok=false;
                            break;
                        }
                    }
                    for(int x=1;x<=n-k-z && ok;x++) {
                        int fi=0;
                        int fj=x;
                        if(x!=1) cur[maxn-x]=max(cur[maxn-x],cur[maxn-x+1]);
                        //cout<<z<<" - "<<x<<" "<<fi+cur[maxn-x]<<" "<<fj+cur[maxn-x]<<endl;
                        while(fj+cur[maxn-x]<n && s[fi+cur[maxn-x]][fj+cur[maxn-x]]=='0') cur[maxn-x]++;
                        if(fj+cur[maxn-x]<n) {
                            t[fi+cur[maxn-x]][fj+cur[maxn-x]]='0';
                            cur[maxn-x+1]=max(cur[maxn-x+1],cur[maxn-x]+1);
                        }
                        else {
                            ok=false;
                            break;
                        }
                    }
                }
            }
            else {
                ok=false;
                break;
            }
        }
        if(!ok) printf("NO\n");
        else {
            printf("YES\n");
            for(int i=0;i<n;i++) {
                printf("%s\n",t[i]);
            }
        }
    }
    return 0;
}