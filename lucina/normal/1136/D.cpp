#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,s[maxn],p[maxn],u,v;
vector<int> a[maxn];
bool c[maxn];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
    }
    int pos=n,b=s[n],sum=0;;
        c[b]=true;
    for(int i=n-1;i>=1;i--){
        sum=0;
        for(auto j:a[s[i]]){
            sum+=(c[j]);
        }
        if(sum==pos-i){
            pos--;
        }
        else
            c[s[i]]=true;
    }
    printf("%d\n",n-pos);
}