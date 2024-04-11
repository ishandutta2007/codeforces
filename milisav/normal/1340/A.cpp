#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
int p[maxn];
int d[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&p[i]);
            d[p[i]]=i;
        }
        int m=n;
        bool pos=true;
        int i=1;
        for(i=1;i<=n && pos;) {
            if(d[i]==m) {
                i++;
                m--;
                continue;
            }
            int k=d[i];
            int nm=k-1;
            while(k<m) {
                //cout<<m<<" "<<k<<" "<<i<<endl;
                k++;
                i++;
                //cout<<m<<" "<<k<<" "<<i<<endl;
                if(p[k]!=i) {
                    pos=false;
                    break;
                }
            }
            if(pos) i++;
            m=nm;
        }
        if(pos) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}