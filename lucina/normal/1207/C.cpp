#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int T,n,a,b;
bool d[maxn];
long long ans;
 
int main(){
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d%d%d",&n,&a,&b);
        for(int i=1;i<=n;i++)
            scanf("%1d",&d[i]);
        vector<int> s;
        for(int i=1;i<=n;i++){
            int j=i;
            while(j<=n&&d[j]==d[i])
            j++;
            j--;
            if(d[i]==0)s.push_back(j-i);
            else{
                int len=j-i+1;
                ans+=2LL*b*(len+1);
                ans+=(1LL*a*(len));
            }
            i=j;
        }
      ///  printf("%lld\n",ans);
        int r=(int)s.size();
        ///a line b pillar
        if(r==1){
            ans=1LL*(n+1)*b;
            ans+=(1LL*(n)*a);
        }
        else{
        for(int i=0;i<r;i++){
            if(i==0||i==r-1){
                ans+=(1LL*(s[i]+1)*b);
                ans+=(1LL*(s[i])*a);
                ans+=(2LL*a);
            }
            else{
                if(s[i]==0){
                    ans+=(1LL*a);
                    continue;
                }
                long long c1=(2LL*b*s[i])+(1LL*a*(s[i]+1));
                long long c2=(1LL*b*s[i])+(1LL*a*(s[i]-1))+(4LL*a);
                ans+=min(c1,c2);
            }
        }
        }
        printf("%lld\n",ans);
    }
}
/*
    Good Luck
        -Lucina
*/