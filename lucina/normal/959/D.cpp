#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,N=2750131;
int a[maxn],b[maxn];
vector<int> prime;
vector<int> pr[maxn];
bool p[N+5];
void seive(){
   for(int i=2;i<=N;i++){
        if(p[i]==0){
            prime.push_back(i);
    for(int j=i;j<=N;j+=i){
        if(p[j]==0)p[j]=1;
        if(j<maxn)
        pr[j].push_back(i);
    }
    }
   }
   return;
}
int n;

int main(){
    seive();
    for(int i=1;i<=N;i++)
        p[i]=false;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
            bool ok=true;
        for(int j:pr[a[i]]){
            ok&=(!p[j]);
            if(!ok)break;
        }
        if(ok){
            for(int j:pr[a[i]])
            p[j]=true;
            b[i]=a[i];
        }
        else{
            int ans=-1;
            for(int j:prime){
                if(j>a[i]&&!p[j]){
                    ans=j;
                    break;
                }
            }
            for(int j=a[i]+1;j<=ans;j++){
                ok=true;
                for(int c:pr[j]){
                    ok&=(!p[c]);
                }
                if(ok){
                    ans=j;
                    break;
                }
            }
            for(int j:pr[ans]){
                p[j]=true;
            }
            b[i]=ans;
            int pt=i+1;
                for(int j:prime){
                    if(!p[j]){
                        b[pt]=j;
                        pt++;
                }
                if(pt>n)break;
            }
            i=n;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
}