#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
char a[100];
char b[100];
bool pos[100][2];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        scanf("%s",a);
        scanf("%s",b);
        bool ok=true;
        for(int i=1;i<m;i++) {
            if(b[i]!=a[i+n-m]) ok=false;
        }
        if(ok) {
            pos[0][a[0]-'0']=true;
            pos[0][(a[0]-'0')^1]=false;
            for(int i=1;i<n;i++) {
                pos[i][(a[i]-'0')]=true;
                if(pos[i-1][(a[i]-'0')^1]) pos[i][(a[i]-'0')^1]=true;
                else pos[i][(a[i]-'0')^1]=false;
            }
            if(!pos[n-m][b[0]-'0']) ok=false;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}