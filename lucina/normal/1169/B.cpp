#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,x,y;
pair<int,int> a[maxn];
vector<int> b;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    x=a[1].first;
    bool ch=true;
    for(int i=2;i<=m;i++){
        if((a[i].first!=x)&&(a[i].second!=x)){
            b.push_back(i);
        }
    }
    if(b.empty())return !printf("YES");
    y=a[b[0]].first;
    for(int i=1;i<b.size();i++){
        if((a[b[i]].first!=y)&&(a[b[i]].second!=y)){
           ch=false;
           }
    }
    if(ch)return !printf("YES");
   // cout<<"Here\n";
    ch=true;y=a[b[0]].second;
    for(int i=1;i<b.size();i++){
        if((a[b[i]].first!=y)&&(a[b[i]].second!=y)){
           ch=false;
           }
    }
    if(ch)return !printf("YES");
        x=a[1].second;
        b.clear();
    for(int i=2;i<=m;i++){
        if((a[i].first!=x)&&a[i].second!=x){
            b.push_back(i);
        }
    }
    ch=true;
    if(b.empty())return !printf("YES");
    y=a[b[0]].first;
    for(int i=1;i<b.size();i++){
        if((a[b[i]].first!=y)&&(a[b[i]].second!=y)){
           ch=false;
           }
    }
    if(ch)return !printf("YES");
    ch=true;y=a[b[0]].second;
    for(int i=1;i<b.size();i++){
        if((a[b[i]].first!=y)&&(a[b[i]].second!=y)){
           ch=false;
           }
    }
    if(ch)return !printf("YES");
    printf("NO");
}