#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
int n,m;
int s[6000];
int c[6000];
int rc[6000];
int ct[6000];
int f[6000];
int h[6000];
vector<int> sl[6000];
int vl[5002][5002];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    for(int i=1;i<=m;i++) {
        scanf("%d %d",&f[i],&h[i]);
        sl[f[i]].push_back(h[i]);
    }
    for(int i=1;i<=n;i++) {
        sort(sl[i].begin(),sl[i].end());
        for(int j=0;j<sl[i].size();j++) {
            vl[i][sl[i][j]]++;
        }
        for(int j=1;j<=n;j++) vl[i][j]+=vl[i][j-1];
    }
    int ans=0;
    long long pans=1;
    for(int i=0;i<=n;i++) {
        int cur=0;
        long long pcur=1;
        for(int j=1;j<=n;j++) c[j]=rc[j]=0;
        for(int j=1;j<=i;j++) c[s[j]]++;
        for(int j=n;j>i;j--) rc[s[j]]++;
        for(int j=1;j<=n;j++) {
            int a=min(c[j],rc[j]);
            int b=max(c[j],rc[j]);
            if(i>0 && j==s[i] && vl[j][c[j]]==vl[j][c[j]-1]) pcur=0;
            if(sl[j].size()>=2) {
                if(sl[j][0]<=a && sl[j][1]<=b) {
                    long long a1=vl[j][b];
                    long long a2=vl[j][a];
                    cur+=2;
                    if(i>0 && j==s[i]) {
                        if(a==c[j]) {
                            pcur=(pcur*(a1-1))%mod;
                        }
                        else {
                            if(a1==a2) pcur=(pcur*(a2-1))%mod;
                            else pcur=(pcur*a2)%mod;
                        }
                    }
                    else pcur=(pcur*((a1-a2)*a2+a2*(a2-1)))%mod;
                }
                else {
                    if(sl[j][0]<=b) {
                        long long a1=vl[j][b];
                        long long a2=vl[j][a];
                        if(i>0 && j==s[i]) {
                            pcur=pcur;
                        }
                        else pcur=(pcur*(a1+a2))%mod;
                        cur++;
                    }
                }
            }
            else {
                if(sl[j].size()>=1) {
                    if(sl[j][0]<=b) {
                        long long a1=vl[j][b];
                        long long a2=vl[j][a];
                        if(i>0 && j==s[i]) {
                            pcur=pcur;
                        }
                        else pcur=(pcur*(a1+a2))%mod;
                        cur++;
                    }
                }
            }
        }

        if(i!=0) {
            if(cur>ans) {
                ans=cur;
                pans=pcur;
            }
            else {
                if(cur==ans) {
                    pans+=pcur;
                    pans%=mod;
                }
            }
        }
        else {
            if(cur>ans) {
                ans=cur;
                pans=pcur;
            }
            else {
                if(cur==ans) {
                    pans+=pcur;
                    pans%=mod;
                }
            }
        }
    }
    if(ans==0) {
        printf("0 1");
        return 0;
    }
    printf("%d %lld",ans,pans);
    return 0;
}