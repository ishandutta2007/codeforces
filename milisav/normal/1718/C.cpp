#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int lpr[maxn];
int t;
int n,q;
int a[maxn];
long long sm[7][maxn];
int fact[7];
int rem[7];
int m;
multiset<long long> st[7];
inline void clear() {
    for(int i=0;i<m;i++) {
        for(int j=0;j<rem[i];j++) {
            sm[i][j]=0;
        }
        st[i].clear();
    }
}
inline void update(int i,int val) {
    for(int j=0;j<m;j++) {
        int pos=i%rem[j];
        multiset<long long>::iterator it;
        it=st[j].find(sm[j][pos]);
        st[j].erase(it);
        sm[j][pos]+=1ll*val*rem[j];
        st[j].insert(sm[j][pos]);
    }
}
inline long long ans() {
    long long ret=0;
    for(int j=0;j<m;j++) {
        ret=max(ret,(*st[j].rbegin()));
    }
    return ret;
}
int main() {
    for(int i=2;i<maxn;i++) {
        if(lpr[i]==0) {
            lpr[i]=i;
            for(long long j=1ll*i*i;j<maxn;j+=i) {
                if(lpr[j]==0) {
                    lpr[j]=i;
                }
            }
        }
    }
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&q);
        int tn=n;
        int ppr=1;
        m=0;
        while(tn>1) {
            if(lpr[tn]!=ppr) {
                fact[m]=lpr[tn];
                rem[m]=n/lpr[tn];
                m++;
            }
            ppr=lpr[tn];
            tn/=lpr[tn];
        }
        clear();
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            for(int j=0;j<m;j++) {
                int pos=i%rem[j];
                sm[j][pos]+=1ll*a[i]*rem[j];
            }
        }
        for(int j=0;j<m;j++) {
            for(int i=0;i<rem[j];i++) {
                st[j].insert(sm[j][i]);
            }
        }
        printf("%lld\n",ans());
        while(q--) {
            int i;
            int nai;
            scanf("%d %d",&i,&nai);
            i--;
            update(i,nai-a[i]);
            a[i]=nai;
            printf("%lld\n",ans());
        }
    }
    return 0;
}