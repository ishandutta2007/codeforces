#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int b[5][160];
bool used[160];
struct st{
    int val;
    int x,y;
    bool operator <(const st & a)const{
        return val > a.val;
    }
};
int g[6][6];
int bf(int i,int j){
    int cur =0;
    for(int x=0;x<4;x++){
        for(int v = 0 ;v <4;v++){
            g[0][v] = b[(v+x)%4][i];
            }
            for(int y= 0 ;y<4;y++){
                for(int u =0 ;u<4;u++){
                    g[1][u] = b[(y+u)%4][j];
                }
                    int now = 0;
                    for(int xx=0;xx<4;xx++){
                        now += max(g[0][xx],g[1][xx]);
                    }
                    cur =max(cur,now);
            }
        }
    return cur;
}

bool vis[6];

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t -- ){
        scanf("%d%d",&n,&m);
        vector<st> a;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
            scanf("%d",&b[i][j]);
            a.push_back({b[i][j],i,j});
        }
        sort(a.begin(),a.end());
        if(n == 1){
            printf("%d\n",a[0].val);
            continue;
        }
        if(n == 2){
            printf("%d\n",a[0].val + a[1].val);
            continue;
        }
        if(n == 3){
            printf("%d\n",a[0].val + a[1].val + a[2].val);
            continue;
        }
        memset(used,false,sizeof(used));
        int base = a[0].val+ a[1].val + a[2].val + a[3].val;
        set<int> ss = {a[0].y,a[1].y,a[2].y,a[3].y};
        if((int)ss.size() >=3 || (int)ss.size()==1){
            printf("%d\n",base);
            continue;
        }
        int ans = 0;
        int shit1 = *ss.begin();
        int shit2 = *ss.rbegin();
        assert(shit1 != shit2);
        int x =  shit1;
        int y = shit2;
        ans =max(ans,bf(shit1,shit2));
        for(int k=4;k<8;k++){
            if(a[k].y != x && a[k].y != y){
                ans = max(ans,base - a[3].val + a[k].val);
            }
        }
        for(int i =8;i<(int)a.size();i++){
            if(a[i].y != x && a[i].y != y)
                ans = max(ans,base-a[3].val+a[i].val);
        }
        printf("%d\n",ans);
    }
}
/*
    Good Luck
        -Lucina
*/


/**
a5  a7
a1  a2
a4  a6
a8  a3
*/