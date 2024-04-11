#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int a[maxn];
int t,n;
map<int,bool> mp;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        mp.clear();
        mp[0]=true;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        a[n+1]=0;
        int ans=0;
        int cur_len=0;
        int prev=-1;
        int cxor=0;
        for(int i=1;i<=n+1;i++) {
            if(a[i]==0) {
                ans+=(cur_len+1)/2;
                cur_len=0;
            }
            else {
                if(prev==a[i]) cur_len++;
                else {
                    ans+=(cur_len+1)/2;
                    if(cur_len%2==0) {
                        mp.clear();
                        cxor=a[i];
                        mp[a[i]]=true;
                        mp[0]=true;
                    }
                    else {
                        if(mp[cxor^a[i]^a[i+1]]==true) {
                            a[i]=a[i+1];
                            cxor=a[i];
                            mp.clear();
                            mp[0]=true;
                            mp[a[i]]=true;
                        }
                        else {
                            cxor^=a[i];
                            mp[cxor]=true;
                        }
                    }
                    prev=a[i];
                    cur_len=1;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}