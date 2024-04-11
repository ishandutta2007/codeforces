#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,z,t[maxn];
vector<int> d;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        d.push_back(x);
        if(x)t[x]=i;
    }
    if(n==1){
        return !printf("%d\n",t[1]==0?1:0);
    }
    if(d.back()>0){
        bool s=true;
        int cur=d.back();
        for(int i=n-2;i>=0;i--){
            if(d[i]>=1&&d[i]+1==d[i+1])cur=d[i];
            else break;
            }
            if(cur==1){
                for(int i=d.back()+1;i<=n;i++){
                    s&=(t[i]==0||t[i]<=i-d.back()-1);
                }

            if(s)return !printf("%d\n",n-d.back());
        }
        }
    int ma=0;
    for(int i=1;i<=n;i++){
        if(t[i]){
            ma=max(ma,t[i]-i+1);
        }
    }
    printf("%d\n",ma+n);
}