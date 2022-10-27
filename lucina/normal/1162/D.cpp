#include<bits/stdc++.h>
using namespace std;
int n,m,u,v;
vector<pair<int,int>>a;
bool ch(int c){
    vector<pair<int,int>> b=a;
    for(auto &i:b){
        i.first+=c;
        i.second+=c;
        if(i.first>n)i.first-=n;
        if(i.second>n)i.second-=n;
        if(i.first>i.second)swap(i.first,i.second);
    }
    sort(b.begin(),b.end());
    return b==a;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        if(u>v)swap(u,v);
        a.push_back(make_pair(u,v));
    }
    sort(a.begin(),a.end());
    int x=sqrt(n);
    if(ch(1))return printf("Yes"),0;
    for(int i=x;i>=2;i--){
        if(n%i==0){
            if(ch(i)||ch(n/i)){
                printf("Yes");
                return 0;
            }
        }
    }
    printf("No");
    return 0;

}