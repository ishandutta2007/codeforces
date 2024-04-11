#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
bool isprime(int x){
    for(int i=sqrt(x);i>=2;i--){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
int n,need;
vector<pair<int,int>> a;
void ans(){
    printf("%d\n",(int)a.size());
    for(auto i:a){
        printf("%d %d\n",i.first,i.second);
    }
    exit(0);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        a.push_back({i,i+1});
    }
    a.push_back({n,1});
    if(isprime(n)){
        ans();
    }
    int x=n+1;need=1;
    while(!isprime(x)){
        need++;
        x++;
    }
    for(int i=1;i<=need;i++){
        a.push_back({i,i+n/2});
    }
    ans();
}
/*
    Good Luck
        -Lucina
*/