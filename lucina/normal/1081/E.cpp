#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a,n,sq[maxn];
vector<pair<int,int>> b[maxn];
int main(){
    for(int i=1;i<=int(2e5);i++){
        for(int j=i+1;true;j++){
            if(((long long)1*(j-i)*(j+i))>int(2e5))
                break;
            else{
                b[(j-i)*(j+i)].push_back({i,j});
            }
        }
    }
    scanf("%d",&n);
    for(int i=2;i<=n;i+=2){
        scanf("%d",&a);
        for(int j=0;j<b[a].size();j++){
            if(sq[i-2]<b[a][j].first){
                sq[i-1]=b[a][j].first,sq[i]=b[a][j].second;
                break;
            }
        }
        if(sq[i]==0){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++){
        printf("%lld ",(long long)sq[i]*sq[i]-(long long)sq[i-1]*sq[i-1]);
    }
}