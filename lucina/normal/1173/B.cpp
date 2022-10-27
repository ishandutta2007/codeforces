#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,r;
vector<pair<int,int>> a;

int main(){
    scanf("%d",&n);
    int x=1,y=1;
    while(n--){
        a.push_back(make_pair(x,y));
        r=max(r,x);r=max(r,y);
        if(x==y)x++;
        else y++;
    }
    printf("%d\n",r);
    for(auto i:a)
        printf("%d %d\n",i.first,i.second);
}