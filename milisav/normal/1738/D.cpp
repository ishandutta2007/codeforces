#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int t;
int n,k;
int b[maxn];
int a[maxn];
vector<int> id[maxn];
void prnt() {
    printf("%d\n",k);
    for(int i=1;i<=n;i++) {
        printf("%d",a[i]);
        if(i!=n) printf(" ");
        else printf("\n");
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        k=0;
        for(int i=0;i<=n+1;i++) id[i].clear();
        for(int i=1;i<=n;i++) {
            scanf("%d",&b[i]);
        }
        bool az=true;
        for(int i=1;i<=n;i++) {
            if(b[i]!=0) az=false;
        }
        if(az) {
            k=0;
            for(int i=1;i<=n;i++) {
                a[i]=i;
            }
            prnt();
        }
        else {
            bool an=true;
            for(int i=1;i<=n;i++) {
                if(b[i]!=n+1) an=false;
            }
            if(an) {
                k=n;
                for(int i=1;i<=n;i++) {
                    a[i]=i;
                }
                prnt();
            }
            else {
                for(int i=1;i<=n;i++) {
                    id[b[i]].push_back(i);
                }
                int cnt=0;
                int bg=0;
                if(id[bg].size()==0) bg=n+1;
                int i=1;
                int tk=1;
                if(bg==0) tk=0;
                while(cnt!=n) {
                    k+=tk*id[bg].size();
                    cnt+=id[bg].size();
                    int nx=-1;
                    for(auto u:id[bg]) {
                        if(id[u].size()!=0) nx=u;
                        else {
                            a[i]=u;
                            i++;
                        }
                    }
                    if(cnt!=n) {
                        a[i]=nx;
                        i++;
                    }
                    bg=nx;
                    tk=1-tk;
                }
                prnt();
            }
        }
    }
    return 0;
}