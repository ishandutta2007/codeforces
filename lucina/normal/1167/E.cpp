#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,a[maxn],x,l[maxn],r[maxn],last,bl,br;
long long ans;
vector<int> p[maxn];
bool ok(int i,int j){
    if(i-1>bl||j+1<br)return false;
    return l[i-1]<r[j+1];
}

int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[a[i]].push_back(i);
        }
    for(int i=1;i<=x;i++){
        if(p[i].empty()){
            l[i]=last;
            bl=i;
        }
        else{
            bool ch=true;
            for(int j:p[i])
                ch&=(j>last);
            if(!ch)break;
            last=p[i].back();
            l[i]=last;bl=i;
        }
    }
    last=n+1;
    r[x+1]=last;
    for(int i=x;i>=1;i--){
        if(p[i].empty()){
            r[i]=last;
            br=i;
            }
        else{
            bool ch=true;
            for(int j:p[i])
                ch&=(j<last);
            if(!ch)break;
            last=p[i][0];
            r[i]=last;br=i;
        }
    }
    int pt=1;
   /* for(int i=1;i<=x;i++)
        printf("%d ",l[i]);
    printf("\n");
    for(int i=1;i<=x;i++)
        printf("%d ",r[i]);
    printf("\n");*/
    //cout<<ok(3,3)<<endl;
    for(int i=1;i<=x;i++){
        if(pt<i)pt=i;
        while(!ok(i,pt)&&pt<=x)pt++;
        if(pt==x+1)break;
      //  cout<<i<<" "<<pt<<endl;
        ans+=(x-pt+1);
    }
    printf("%lld\n",ans);
}