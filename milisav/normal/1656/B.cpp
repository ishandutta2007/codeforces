#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
int a[maxn];
int k;
set<int> s;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        s.clear();
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            s.insert(a[i]);
        }
        bool ok=false;
        for(int i=0;i<n;i++) {
            if(s.find(k+a[i])!=s.end()) ok=true;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}