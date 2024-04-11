#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> s[2000000];
long long cmax[2000000];
long long cmin[2000000];
int main() {
    scanf("%d",&n);
    long long a=0;
    for(int i=0;i<n;i++) {
        int l,t;
        scanf("%d",&l);
        bool asc=false;
        for(int j=0;j<l;j++) {
            scanf("%d",&t);
            s[i].push_back(t);
            if(j>0 && s[i][j]>s[i][j-1]) {
                asc=true;
            }
        }
        if(asc) a++;
        else {
            cmax[s[i][0]]++;
            cmin[s[i].back()]++;
        }
    }
    long long ans=0;
    ans=2*a*n-a*a;
    long long cnt=0;
    for(int i=1000000;i>=0;i--) {
        ans+=cmin[i]*cnt;
        cnt+=cmax[i];
    }
    printf("%lld",ans);
    return 0;
}