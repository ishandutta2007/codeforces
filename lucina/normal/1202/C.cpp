#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,pre[maxn];
char s[maxn];
bool sh(const vector<int> &a,int &h){
    n=(int)a.size();
    int ma=0,mi=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i-1];
        ma=max(ma,pre[i]);
        mi=min(mi,pre[i]);
        }
            h=ma-mi+1;
            int p1=-1,p2=-1;
            for(int i=0;i<=n;i++){
                if(pre[i]==ma){
                    p1=i;
                }
                if(pre[i]==mi&&p2==-1)
                    p2=i;
            }
            if(p1<p2)return true;
            p1=p2=-1;
            for(int i=0;i<=n;i++){
                if(pre[i]==mi)
                    p1=i;
                if(pre[i]==ma&&p2==-1)
                    p2=i;
            }
            if(p1<p2)return true;
            return false;
}
int main(){
    int T,h,w;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        vector<int> a,b;
        for(int i=1;i<=n;i++){
            if(s[i]=='W')a.push_back(1);
            else if(s[i]=='S')a.push_back(-1);
            else if(s[i]=='D')b.push_back(1);
            else if(s[i]=='A')b.push_back(-1);
        }
        bool d1=false,d2=false;
        if(a.empty())
            h=1;
        else
            d1=sh(a,h);
        if(b.empty())
            w=1;
        else
            d2=sh(b,w);
        long long ans=1LL*w*h;
        ans=min(ans,1LL*max(b.empty()?1:2,w-d2)*h);
        ans=min(ans,1LL*max(a.empty()?1:2,h-d1)*w);
        printf("%lld\n",ans);
    }
}
/*
    Good Luck
        -Lucina

*/