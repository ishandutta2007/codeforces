#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,N=1e7+5;
int ct[N],a[maxn],n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ct[a[i]]++;
    }
    long long cur=1e18;
    int M1,M2;
    for(int i=1;i<N;i++){
        int c=0,m1=N,m2=N;
        for(int j=i;j<N;j+=i){
            if(ct[j]){
                if(j<m2){
                    m2=j;
                }
                if(m2<m1)swap(m1,m2);
            }
            if(ct[j]>1){
                if(j<m2)
                    m2=j;
                if(m2<m1)swap(m1,m2);
            }
        }
        if(m1<N&&m2<N){
            if(1LL*m1*(m2/i)<cur){
                cur=1LL*(m1)*(m2/i);
                M1=m1,M2=m2;
            }
        }
    }
    if(cur==1e18){
        vector<pair<int,int>> v;
        int x=0,y=0;a[0]=N;
        for(int i=1;i<=n;i++){
            if(a[i]<a[y])y=i;
            if(a[y]<a[x])swap(x,y);
        }
        if(x>y)swap(x,y);
        return ! printf("%d %d\n",x,y);
    }
    int x,y;
    for(int i=1;i<=n;i++){
        if(a[i]==M1){
            x=i;break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==M2&&i!=x){
            y=i;break;
        }
    }
    if(x>y)swap(x,y);
    printf("%d %d\n",x,y);
}