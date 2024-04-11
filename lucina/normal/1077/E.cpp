#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,ans,a[maxn],b,c,r,ct;
bool g[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    vector<int> f;
    for(int i=1;i<=n;){
        b=a[i],ct=0;
        while(a[i]==b){
            i++,ct++;
        }
        f.push_back(ct);
    }
    sort(f.begin(),f.end());
    for(int i=1;i<=n;i++){
        x=i;
        r=f.size()-1,ct=0;
        while(true){
            if(r<0)
            break;
            if(f[r]>=x){
                ct+=x;
                r--;
                if(x%2)
                    break;
                else
                    x=x/2;
            }
            else
                break;
        }
        ans=max(ans,ct);
    }
    printf("%d\n",ans);
}