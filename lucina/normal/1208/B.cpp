#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn];
bool ch(int x){
    map<int,int> s;
    for(int i=x+1;i<=n;i++){
        s[a[i]]++;;
    }
    if((int)s.size()==n-x)return true;
    for(int i=1;i<=n-x;i++){
        s[a[i+x]]--;
        if(s[a[i+x]]==0)s.erase(s.find(a[i+x]));
        s[a[i]]++;
        if((int)s.size()==n-x)return true;
    }
    return false;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l=0,r=n-1,mid,ans=n-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(ch(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/