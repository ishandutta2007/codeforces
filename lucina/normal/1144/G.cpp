#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],x,b[maxn];
vector<int> in,de;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    bool c[2];
    for(int i=1;i<n;i++){
        c[0]=c[1]=false;
        if(in.empty()||a[i]>in.back())
            c[0]=true;
        if(de.empty()||a[i]<de.back())
            c[1]=true;
        if(c[1]&&c[0]){
            if(a[i+1]>a[i])
                in.push_back(a[i]);
            else
                de.push_back(a[i]),b[i]=1;
            continue;
        }
        if(c[0]){
            in.push_back(a[i]);
            continue;
        }
        if(c[1]){
            de.push_back(a[i]),b[i]=1;
            continue;
        }
        printf("NO");
        return 0;
    }
    if(in.empty()||a[n]>in.back()){
        in.push_back(a[n]);
    }
    else if(de.empty()||a[n]<de.back()){
        de.push_back(a[n]);
        b[n]=1;
    }
    if(de.size()+in.size()!=n)
        return printf("NO"),0;
    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);

}