#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
struct pa{
    int l,r;
    bool operator<(const pa z)const{
        return l==z.l?r<z.r:l<z.l;
    }
};
int n,x,r;
vector<pa> a;

int main(){
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x){
            a.push_back({i>=r?i-r+1:1,i+r-1<=n?i+r-1:n});
        }
        }
    sort(a.begin(),a.end());
   /* for(auto i:a){
        printf("%d %d\n",i.l,i.r);
    }*/
    if(a.empty())return !printf("-1");
    int pt=0;
    if(a[0].l!=1)return !printf("-1");
    while(a[pt+1].l==1&&pt+1<(int)a.size())
        pt++;
    int br=a[pt].r;
    int ct=1;
    for(int i=pt+1;i<(int)a.size();i++){
        if(br==n){
            return !printf("%d\n",ct);
        }
        int j=i;
        r=-1;
        if(a[j].l<=br+1)r=a[j].r;
        while(a[j+1].l<=br+1&&j+1<(int)a.size()){
            r=max(r,a[j+1].r);
            j++;
        };
        if(r==-1)return !printf("-1");
        br=max(r,br);
        ct++;
        i=j;
    }
    if(br==n)
    printf("%d\n",ct);
    else
    printf("-1");
}