#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int cnt[3][2];
int t;
int n;
char s[3][maxn];
char o[3*maxn];
int a[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<3;i++) {
            scanf("%s",s[i]);
            cnt[i][0]=cnt[i][1]=0;
            for(int j=0;j<2*n;j++) {
                cnt[i][s[i][j]-'0']++;
            }
        }
        bool fn=false;
        for(int i=0;i<3 && !fn;i++) {
            for(int j=i+1;j<3 && !fn;j++) {
                for(int k=0;k<2 && !fn;k++) {
                    if(min(cnt[i][k],cnt[j][k])>=n) {
                        int m=0;
                        int c=0;
                        int qn=max(cnt[i][k],cnt[j][k]);
                        for(int l=0;l<2*n;l++) a[l]=0;
                        for(int l=0;l<2*n;l++) {
                            if(s[i][l]=='0'+k) {
                                a[m]=max(a[m],c);
                                c=0;
                                m++;
                            }
                            else c++;
                        }
                        a[m]=max(a[m],c);
                        m=0;
                        c=0;
                        for(int l=0;l<2*n;l++) {
                            if(s[j][l]=='0'+k) {
                                a[m]=max(a[m],c);
                                c=0;
                                m++;
                            }
                            else c++;
                        }
                        a[m]=max(a[m],c);
                        m=0;
                        for(int l=0;l<a[0];l++) o[m++]='0'+(1-k);
                        for(int l=1;l<=qn;l++) {
                            o[m++]='0'+k;
                            for(int g=0;g<a[l];g++) {
                                o[m++]='0'+(1-k);
                            }
                        }
                        while(m<3*n) o[m++]='0';
                        o[3*n]=0;
                        printf("%s\n",o);
                        fn=true;
                    }
                }
            }
        }
    }
    return 0;
}