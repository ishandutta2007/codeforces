#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a;
char l[maxn];
vector<int> f[2][27];
vector<pair<int,int>> b;
int main(){
    scanf("%d",&n);
    for(int j=0;j<2;j++){
    scanf("%s",l+1);
    for(int i=1;i<=n;i++){
        if(l[i]=='?')
            f[j][26].push_back(i);
        else
            f[j][l[i]-'a'].push_back(i);
    }
    }
    for(int i=0;i<26;i++){
        while(f[0][i].size()&&f[1][i].size()){
            b.push_back({f[0][i].back(),f[1][i].back()});
            f[0][i].pop_back();f[1][i].pop_back();
        }
    }
    for(int i=0;i<26;i++){
        while(f[0][26].size()&&f[1][i].size()){
            b.push_back({f[0][26].back(),f[1][i].back()});
            f[0][26].pop_back();f[1][i].pop_back();
        }
    }
    for(int i=0;i<26;i++){
        while(f[1][26].size()&&f[0][i].size()){
            b.push_back({f[0][i].back(),f[1][26].back()});
            f[1][26].pop_back();f[0][i].pop_back();
        }
    }
    while(f[0][26].size()&&f[1][26].size()){
         b.push_back({f[0][26].back(),f[1][26].back()});
            f[1][26].pop_back();f[0][26].pop_back();
    }
    printf("%d\n",b.size());
    for(auto i:b)
    printf("%d %d\n",i.first,i.second);
}