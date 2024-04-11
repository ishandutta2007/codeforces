#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
int f[maxn][maxn],n,m,a,b,g,x,y,z,mi[maxn][maxn];

int main(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    scanf("%d%d%d%d",&g,&x,&y,&z);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=g;
            g=(int)((1LL*g*x+y)%z);
        }
    }
    for(int i=1;i<=n;i++){
            deque<pair<int,int>> d;
        for(int j=1;j<=m;j++){
            while(!d.empty()&&j-d.front().second>=b)
                d.pop_front();
            while(!d.empty()&&d.back().first>=f[i][j])
                d.pop_back();
            d.push_back({f[i][j],j});
            if(j>=b)mi[i][j]=d.front().first;
        }
    }
    ///mi[i][j] is minimum from a[i][j-b+1]....->a[i][j]
    long long sum=0;
    for(int j=b;j<=m;j++){
            deque<pair<int,int>> d;
        for(int i=1;i<=n;i++){
            while(!d.empty()&&i-d.front().second>=a)
                d.pop_front();
            while(!d.empty()&&d.back().first>=mi[i][j]){
                d.pop_back();
            }
            d.push_back({mi[i][j],i});
            if(i>=a)sum+=d.front().first;
        }
    }
    printf("%lld\n",sum);

}
/*
    Good Luck
        -Lucina
*/