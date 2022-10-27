#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,q,ma;
int a[maxn];
vector<int> st;
pair<int,int> keep[maxn];

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ma=a[1];
    for(int i=2;i<=n;i++){
        keep[i-1]=make_pair(ma,a[i]);
        if(a[i]>ma){
            st.push_back(ma);
            ma=a[i];
        }
        else{
            st.push_back(a[i]);
        }
    }
    //for(int i:st){
      //  printf("%d ",i);
    
    //printf("\n");
    long long x;
    while(q--){
        scanf("%lld",&x);
        if(x<=n-1){
            printf("%d %d\n",keep[x].first,keep[x].second);
        }
        else{
            x-=(n);
            x%=(n-1);
            printf("%d %d\n",ma,st[x]);
        }
    }
}