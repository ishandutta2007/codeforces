#include<bits/stdc++.h>
using namespace std;
const int maxn=2750131;
int n,a[400005];
int p[maxn+5],id[maxn+5],x,ct[maxn+5];
int pr[maxn+5];
void seive(){
   for(int i=2;i<=maxn;i++){
        if(p[i]==0){
        ++x;
        pr[x]=i;
        id[i]=x;
    for(int j=i;j<=maxn;j+=i){
        if(p[j]==0)p[j]=i;
    }
    }
   }
   return;
}

int main(){
    seive();
    scanf("%d",&n);
    vector<int> sleepy,wake;
    for(int i=1;i<=2*n;i++){
        scanf("%d",&x);
        ct[x]++;
        if(id[x]==0){
            sleepy.push_back(x);
        }
        else{
            wake.push_back(x);
        }
    }
    sort(sleepy.begin(),sleepy.end());
    reverse(sleepy.begin(),sleepy.end());
    vector<int> Ihatethisround;
    for(int i:sleepy){
        if(ct[i]==0){
            continue;
        }
        ct[i]--;
        Ihatethisround.push_back(i);
        ct[i/p[i]]--;
    }
    sort(wake.begin(),wake.end());
    for(int i:wake){
        if(ct[i]==0)continue;
        Ihatethisround.push_back(i);
        ct[i]--;
        ct[pr[i]]--;
    }
    for(int i:Ihatethisround)
        printf("%d ",i);
}