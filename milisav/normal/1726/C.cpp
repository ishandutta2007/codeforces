#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int t;
int n;
char s[maxn];
int pref[maxn];
map<int,int> mp;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        scanf("%s",s+1);
        mp.clear();
        pref[0]=0;
        for(int i=1;i<=2*n;i++) {
            pref[i]=pref[i-1];
            if(s[i]=='(') pref[i]++;
            else pref[i]--;
        }
        int ans=0;
        for(int i=2*n;i>0;i--) {
            if(s[i]=='(' && (mp.find(pref[i-1])==mp.end() || s[mp[pref[i-1]]+1]!='(')) ans++;
            mp[pref[i]]=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}