#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
long long t;
int n;
char s[maxn];
int cnt[60];
int main() {
    scanf("%d %lld",&n,&t);
    scanf("%s",s);
    for(int i=0;i<n-2;i++) {
        cnt[s[i]-'a']++;
    }
    long long x=s[n-2]-'a';
    t+=(1ll<<x);
    x=s[n-1]-'a';
    t-=(1ll<<x);
    t=abs(t);
    long long cur=0;
    for(long long x=51;x>=0;x--) {
        if(t&(1ll<<x)) cur+=(1ll<<x);
        //cout<<x<<" "<<cur<<endl;
        while((1ll<<x)<=abs(cur) && cnt[x]>0) {
            cnt[x]--;
            if(cur>=0) cur-=(1ll<<x);
            else cur+=(1ll<<x);
        }
        if(cnt[x]&1) {
            if(cur>=0) cur-=(1ll<<x);
            else cur+=(1ll<<x);
        }
    }
    if(cur!=0) {
        printf("No");
        return 0;
    }
    printf("Yes");
    return 0;
}