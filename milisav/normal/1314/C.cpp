#include<bits/stdc++.h>
using namespace std;
int n,m;
long long k;
char s[5000];
char t[5000];
bool pos[5000];
int ls[5000];
long long dp[2000];
long long suf[2000][2000];
int pt[2000];
int mv[2000];
long long inf=1e18;
int l;
bool tst() {
    int sl=l+1;
    for(int i=0;i<=n;i++) {
        ls[i]=-1;
        pt[i]=i;
        mv[i]=0;
    }
    int pp=n;
    suf[n][0]=1;
    int fd;
    for(int i=n-1;i>=0;i--) {
        pos[i]=true;
        pp=-1;
        for(int j=0;j<sl;j++) {
            if(i+j>=n) {
                pos[i]=false;
                break;
            }
            if(s[i+j]>t[j]) {
                pp=i+j+1;
                break;
            }
            if(s[i+j]<t[j]) {
                pos[i]=false;
                break;
            }
        }
        if(i==0) {
            for(int x=0;x<=m;x++) dp[x]=0;
        }
        if(pos[i]) {
            if(pp==-1) pp=min(i+sl,n);
            int c=pt[pp];
            mv[i]=0;
            if(i==0) {
                for(int x=1;x<=mv[c]+1;x++) dp[x]=suf[c][x-1];
            }
            int r=max(mv[c]+1,mv[pt[i+1]]);
            for(int x=0;x<=m && x<=r;x++) {
                suf[i][x]=suf[pt[i+1]][x];
                if(x>mv[pt[i+1]]) suf[i][x]=0;
                if(x>0 && x-1<=mv[c]) {
                    suf[i][x]=min(inf,suf[i][x]+suf[c][x-1]);
                }
                //if(i==0) cout<<x<<" "<<suf[i][x]<<endl;
            }
            mv[i]=r;
        }
        else pt[i]=pt[i+1];
    }
    //cout<<sl<<" "<<t<<" "<<suf[pt[0]][m]<<" "<<suf[pt[1]][m]<<" "<<dp[m]<<endl;
    return dp[m]>=k;
}
int bin() {
    int x=0,y=26;
    while(x<y) {
        int m=(x+y+1)>>1;
        t[l]='a'+m-1;
        if(tst()) x=m;
        else y=m-1;
    }
    return x;
}
void build() {
    int x=bin();
    while(x!=0) {
        t[l]='a'+x-1;
        l++;
        x=bin();
    }
}
int main() {
    scanf("%d %d %lld",&n,&m,&k);
    scanf("%s",s);
    build();
    for(int i=0;i<l;i++) printf("%c",t[i]);
    return 0;
}