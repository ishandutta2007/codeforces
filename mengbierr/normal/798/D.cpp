#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn=1e5+5;

struct TnT{
    LL a;
    LL b;
    int id;
}T[maxn];

bool cmp(TnT x,TnT y){
    return x.a>y.a;    
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;    
    for(int i=1;i<=n;i++) cin>>T[i].a;
    for(int i=1;i<=n;i++) cin>>T[i].b;
    for(int i=1;i<=n;i++) T[i].id=i;
    sort(T+1,T+n+1,cmp);//a 
    cout<<n/2+1<<endl;//n/2+1,n/2+1,,. 
    cout<<T[1].id<<" ";//,n/2+1,TnT!!! 
    for(int i=2;i<=n;i+=2){
        int j=i;
        if(j<=n&&T[j].b<T[j+1].b) j++;//, 
        cout<<T[j].id<<" ";
    }
    return 0;
}