#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t[maxn],id,q,x;
int tl[maxn],tr[maxn],type[maxn],a[maxn];
char s[2];

int main(){
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        a[i]=a[i-1];
        a[i]++;
        tl[i]=tl[i-1],tr[i]=tr[i-1];
        scanf("%s",s);
        scanf("%d",&x);
        if(s[0]=='L'){
            type[x]=0;
            t[x]=i;
            tl[i]++;
        }
        else if(s[0]=='R'){
            type[x]=1;
            t[x]=i;
            tr[i]++;
        }
        else{
            int ans=maxn;
            if(type[x]){
                ans=min(ans,a[t[x]]-1+tl[i]-tl[t[x]]);
                ans=min(ans,tr[i]-tr[t[x]]);
            }
            else{
                ans=min(ans,a[t[x]]-1+tr[i]-tr[t[x]]);
                ans=min(ans,tl[i]-tl[t[x]]);
            }
        a[i]--;
            printf("%d\n",ans);
        }
    }

}