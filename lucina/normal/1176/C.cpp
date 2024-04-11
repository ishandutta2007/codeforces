#include<bits/stdc++.h>
const int maxn=5e5+10;
using namespace std;
int ans,n,a[maxn];
int b[]={4,8,15,16,23,42};
int t[44];
vector<int> v[maxn];
int r[8];

int main(){
    for(int i=0;i<6;i++){
        t[b[i]]=i+1;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=t[a[i]];
    }
    int now=0;
    r[0]=1e9;
    for(int i=1;i<=n;i++){
        if(r[a[i]-1]){
            r[a[i]-1]--;
            r[a[i]]++;
        }
        else{
            ans++;
        }
    }

    for(int i=1;i<=5;i++)
        ans+=(i*r[i]);
    printf("%d\n",ans);
/*
15
4 8 8 16 15 16 4 23 42
*/
}