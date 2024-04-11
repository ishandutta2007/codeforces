#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,p[maxn],q[maxn],k,inv[maxn],c[maxn];
vector<int> z;
char s[maxn];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&q[i]);
        inv[q[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(inv[p[i]]>i){
        c[i]++;
        c[inv[p[i]]]--;
        }
    }
    for(int i=1;i<=n;i++){
        c[i]+=c[i-1];
        if(c[i]==0){
            z.push_back(i);
        }
    }
    if((int)z.size()<k)return !printf("NO\n");
    int pt=0;
    for(int i=1;i<=n;i++){
        int cur=z[pt];
        for(int j=i;j<=cur;j++){
            s[p[j]]='a'+min(25,pt);
        }
        pt++;
        i=cur;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%c",s[i]);
}
/*
    RIP Edelgard
*/