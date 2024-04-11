#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,q,b,w;
bool sw;
vector<pair<int,int>> a;
vector<pair<int,int>> black;
void ans(){
    printf("YES\n");
    for(auto i:a){
        printf("%d %d\n",i.first+1+sw,i.second);
    }
    return;
}

int main(){
    scanf("%d",&q);
    while(q--){
            a.clear();
            black.clear();
        sw=false;
        scanf("%d%d",&b,&w);
        if(b>w){
            swap(b,w);
            sw=true;
        }
        int tot=1;
        a.push_back({2,2});
        a.push_back({1,2});
        a.push_back({3,2});
        a.push_back({2,3});
        a.push_back({2,1});
        black.push_back({1,1});
        black.push_back({3,1});
        black.push_back({1,3});
        black.push_back({3,3});
        if(w<=4){
                int res=4-w;
            while(res--){
                a.pop_back();
            }
            for(int i=0;i<b-1;i++){
                a.push_back(black[i]);
            }
            ans();
            continue;
        }
        w-=4;
        int x=2,y=4;
        while(w>3){
            tot++;
            a.push_back({x,y});
            a.push_back({x,y+1});
            a.push_back({x-1,y});
            a.push_back({x+1,y});
            black.push_back({x-1,y+1});
            black.push_back({x+1,y+1});
            y+=2;
            w-=3;
        }
        if(w){
            tot++;
            a.push_back({x,y});
            a.push_back({x,y+1});
            a.push_back({x-1,y});
            a.push_back({x+1,y});
            int res=3-w;
            while(res--)
                a.pop_back();
            black.push_back({x-1,y+1});
            black.push_back({x+1,y+1});
        }
        if(tot>b){
            printf("NO\n");
            continue;
        }
        int res=b-tot;
        for(int i=0;i<res;i++)
            a.push_back(black[i]);
        ans();
    }
}
/*
    Good Luck
        -Lucina
*/