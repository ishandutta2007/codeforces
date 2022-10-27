#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,b[maxn];
pair<int,int> a[maxn];

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i].second*2-1;
        if(i>1)
           printf("%d %d\n",b[i],b[i-1]);
    }
  //  for(int i=1;i<=n;i++)
   //     cout<<b[i]<<' ';
    //cout<<'\n';
    int res,cur=n,des;
    for(int i=1;i<=n;i++){
        res=a[i].second*2;
        des=i+a[i].first-1;
        if(des>=cur){
            b[++cur]=res;
            printf("%d %d\n",res,b[cur-1]);
        }
        else
            printf("%d %d\n",res,b[des]);
    }
}