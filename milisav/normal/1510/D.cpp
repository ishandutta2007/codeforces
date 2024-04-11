#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int n,d;
int a[maxn];
long long prod[10];
long long nprod[10];
long long inf=1e15;
vector<int> ans[10];
vector<int> nans[10];
bool tk[maxn];
int inv[10];
int mp[10];
int omp[10];
int main()
{
    scanf("%d %d",&n,&d);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    if(d==0) {
        int rem=1;
        for(int i=0;i<n;i++) {
            rem=(rem*a[i])%10;
        }
        if(rem==0) {
            printf("%d\n",n);
            for(int i=0;i<n;i++) printf("%d ",a[i]);
        }
        else {
            printf("-1");
        }
        return 0;
    }
    if(d==5) {
        int rem=1;
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(a[i]%2!=0) {
                cnt++;
                rem=(rem*a[i])%10;
            }
        }
        if(rem==d) {
            printf("%d\n",cnt);
            for(int i=0;i<n;i++) {
                if(a[i]%2!=0) {
                    printf("%d ",a[i]);
                }
            }
        }
        else {
            printf("-1");
        }
        return 0;
    }
    if(d%2==0) {
        d=d%5;
        inv[1]=1;
        inv[4]=4;
        inv[2]=3;
        inv[3]=2;
        prod[1]=prod[2]=prod[3]=prod[4]=inf;
        prod[1]=1;
        int ac=1;
        int pcnt=0;
        for(int i=0;i<n;i++) {
            if(a[i]%5==0) continue;
            if(a[i]%2==0) pcnt++;
        }
        if(pcnt==0) {
            printf("-1");
            return 0;
        }
        for(int i=0;i<n;i++) {
            if(a[i]%5==0) continue;
            int r=a[i]%5;
            ac=(ac*r)%5;
            for(int j=1;j<=4;j++) {
                nprod[j]=prod[j];
                nans[j].clear();
                for(auto k:ans[j]) nans[j].push_back(k);
            }
            for(int j=1;j<=4;j++) {
                int nrem=(r*j)%5;
                if(nprod[nrem]>prod[j]*a[i]) {
                    int tcnt=0;
                    if(a[i]%2==0) tcnt++;
                    for(auto k:ans[j]) if(a[k]%2==0) tcnt++;

                    if(tcnt!=pcnt) {
                        nprod[nrem]=prod[j]*a[i];
                        nans[nrem].clear();
                        for(auto k:ans[j]) nans[nrem].push_back(k);
                        nans[nrem].push_back(i);
                    }
                }
            }
            for(int j=1;j<=4;j++) {
                prod[j]=nprod[j];
                ans[j].clear();
                for(auto k:nans[j]) ans[j].push_back(k);
            }
        }
        d=(inv[d]*ac)%5;
        //printf("%d\n\n",d);
        if(prod[d]==inf) {
            printf("-1");
            return 0;
        }
        for(auto v:ans[d]) {
            tk[v]=true;
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(a[i]%5==0 || tk[i]) continue;
            cnt++;
        }
        if(cnt==0) {
            printf("-1");
            return 0;
        }
        printf("%d\n",cnt);
        for(int i=0;i<n;i++) {
            if(a[i]%5==0 || tk[i]) continue;
            printf("%d ",a[i]);
        }
        return 0;
    }
    mp[1]=1;
    mp[2]=3;
    mp[3]=7;
    mp[4]=9;
    inv[1]=1;
    inv[9]=9;
    inv[7]=3;
    inv[3]=7;
    omp[1]=1;
    omp[3]=2;
    omp[7]=3;
    omp[9]=4;
    prod[1]=prod[2]=prod[3]=prod[4]=inf;
    prod[1]=1;
    int ac=1;
    for(int i=0;i<n;i++) {
        if(a[i]%5==0 || a[i]%2==0) continue;
        int r=a[i]%10;
        ac=(ac*r)%10;
        for(int j=1;j<=4;j++) {
            nprod[j]=prod[j];
            nans[j].clear();
            for(auto k:ans[j]) nans[j].push_back(k);
        }
        for(int j=1;j<=4;j++) {
            int nrem=omp[(r*mp[j])%10];
            if(nprod[nrem]>prod[j]*a[i]) {
                nprod[nrem]=prod[j]*a[i];
                nans[nrem].clear();
                for(auto k:ans[j]) nans[nrem].push_back(k);
                nans[nrem].push_back(i);
            }
        }
        for(int j=1;j<=4;j++) {
            prod[j]=nprod[j];
            ans[j].clear();
            for(auto k:nans[j]) ans[j].push_back(k);
        }
    }
    d=omp[(inv[d]*ac)%10];
    if(prod[d]==inf) {
        printf("-1");
        return 0;
    }
    for(auto v:ans[d]) {
        tk[v]=true;
    }
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(a[i]%5==0 || a[i]%2==0 || tk[i]) continue;
        cnt++;
    }
    if(cnt==0) {
        printf("-1");
        return 0;
    }
    printf("%d\n",cnt);
    for(int i=0;i<n;i++) {
        if(a[i]%5==0 || a[i]%2==0 || tk[i]) continue;
        printf("%d ",a[i]);
    }
    return 0;
}