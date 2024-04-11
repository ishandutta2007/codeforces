#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n,m,k;
int a[maxn];
int b[maxn];
vector<pair<int,long long> > va;
vector<pair<int,long long> > vb;
int main() {
    scanf("%d",&t);
    while(t--) {
        va.clear();
        vb.clear();
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++) {
            scanf("%d",&b[i]);
        }
        int pr=0;
        long long pq=0;
        for(int i=0;i<n;i++) {
            int cr=0;
            long long cq=1;
            while(a[i]%m==0) {
                cq=cq*m;
                a[i]/=m;
            }
            cr=a[i];
            if(cr!=pr) {
                va.push_back({pr,pq});
                pr=cr;
                pq=cq;
            }
            else {
                pq+=cq;
            }
        }
        va.push_back({pr,pq});
        pr=0;
        pq=0;
        for(int i=0;i<k;i++) {
            int cr=0;
            long long cq=1;
            while(b[i]%m==0) {
                cq=cq*m;
                b[i]/=m;
            }
            cr=b[i];
            if(cr!=pr) {
                vb.push_back({pr,pq});
                pr=cr;
                pq=cq;
            }
            else {
                pq+=cq;
            }
        }
        vb.push_back({pr,pq});
        bool ok=true;
        if(va.size()!=vb.size()) ok=false;
        else {
            for(int i=0;i<va.size();i++) {
                if(va[i].first!=vb[i].first || va[i].second!=vb[i].second) ok=false;
            }
        }

        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}