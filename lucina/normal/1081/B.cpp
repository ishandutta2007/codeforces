#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],c[maxn],x;
vector <int> f[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=n-a[i];
        }
    for(int i=1;i<=n;i++){
        c[a[i]]++;
    }
    bool ch=true;
    for(int i=1;i<=n;i++){
        if(c[i]){
        if(c[i]%i)
            ch=false;
        }
    }
    int id=1;

    for(int i=1;i<=n;i++){
        for(int k=1;k<=c[i]/i;k++){
        for(int j=1;j<=i;j++){
            f[i].push_back(id);

        }
        id++;
        }
    }
    if(ch){
            printf("Possible\n");
        for(int i=1;i<=n;i++){
            printf("%d ",f[a[i]].back());
            f[a[i]].pop_back();
        }
    }
    else{
        printf("Impossible\n");
    }
}