#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,l,r,mid,x,q,d,id[maxn];
vector<int> a;

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d",&n);
    l=0,r=(int)1e9;
    int ma;
    q=60;
    while(l<=r){
        mid=(l+r)>>1;
        printf("> %d\n",mid);//check whether there is element greater than mid
        fflush(stdout);
        q--;
        scanf("%d",&x);
        if(x){
            l=mid+1;
        }
        else{
            ma=mid;
            r=mid-1;
        }
    }
    for(int i=1;i<=n;i++)
        id[i]=i;
        shuffle(id+1, id+1+n, rng);
    int range=n;
    l=0;
    while(q>0&&l<n){
        printf("? %d\n",id[++l]);
        fflush(stdout);
        scanf("%d",&r);
        a.push_back(r);
        q--;
    }
    sort(a.begin(),a.end());
    if(a.back()!=ma)a.push_back(ma);
    for(int i=1;i<a.size();i++){
        d=__gcd(d,a[i]-a[i-1]);
    }
    printf("! %d %d\n",ma-(n-1)*d,d);
    fflush(stdout);
}