#include<bits/stdc++.h>
using namespace std;
struct P{
    int x,y,id;
    P(int a,int b,int c):x(a),y(b),id(c){}
    bool operator<(const P &p)const{
        return y<p.y;
    }
};

int n;
vector<P>latte[1010];

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        latte[x/1000].push_back(P(x,y,i));
    }


    for(int i=0;i<=1000;i++){
        sort(latte[i].begin(),latte[i].end());
        if(i&1)reverse(latte[i].begin(),latte[i].end());
    }

    for(int i=0;i<=1000;i++){
        for(int j=0;j<latte[i].size();j++){
            printf("%d ",latte[i][j].id+1);
        }
    }
    puts("");


    return 0;
}