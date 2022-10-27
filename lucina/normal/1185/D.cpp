#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
pair<int,int> a[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    if(n==2)return !printf("1");
    int dif=a[3].first-a[2].first;
    bool ch=true;
    for(int i=4;i<=n;i++){
        ch&=(a[i].first-a[3].first==(1LL*(i-3)*dif));
    }
    if(ch)return !printf("%d",a[1].second);
    ch=true;
    dif=a[3].first-a[1].first;
    for(int i=4;i<=n;i++){
        ch&=(a[i].first-a[3].first==(1LL*(i-3)*dif));
    }
    if(ch)return !printf("%d",a[2].second);
    dif=a[2].first-a[1].first;
    long long sum=0;
  //  cout<<dif<<endl;;
    sum=a[2].first;int idx=-1;

    for(int i=3;i<=n;i++){
            //cout<<sum<<endl;
        if(sum+dif!=a[i].first){
            if(idx!=-1)return !printf("-1");
            idx=a[i].second;
        }
        else{
            sum+=dif;
        }
    }
    if(idx==-1){
        return !printf("%d",a[1].second);
    }
    printf("%d",idx);
}
/*
    Good Luck
         -Lucina
*/