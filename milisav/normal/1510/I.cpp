#include<bits/stdc++.h>
#define maxn 2000
#define maxl 12000
using namespace std;
int n,m;
int o[maxn];
char s[maxn];
char ans[10];
long double w[maxl];
mt19937 rng(time(0));
int main() {
    scanf("%d %d",&n,&m);
    w[0]=1;
    for(int i=1;i<maxl;i++) w[i]=w[i-1]/2;
    for(int i=0;i<m;i++) {
        scanf("%s",s);
        long double w0=0;
        long double w1=0;
        for(int j=0;j<n;j++) {
            if(s[j]=='0') w0=w0+w[o[j]];
            else w1=w1+w[o[j]];
        }
        double x = uniform_real_distribution<double>(0,w0+w1)(rng);
        if(x<w0) {
            printf("0\n");
            fflush(stdout);
        }
        else {
            printf("1\n");
            fflush(stdout);
        }
        scanf("%s",ans);
        int mv=m+1;
        for(int j=0;j<n;j++) {
            if(s[j]!=ans[0]) o[j]++;
            mv=min(mv,o[j]);
        }
        for(int j=0;j<n;j++) o[j]-=mv;
    }
    return 0;
}