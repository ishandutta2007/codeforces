#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,dp[maxn],dep,col[maxn],d[2][maxn];
char s[maxn];
vector<pair<char,int>> a;
vector<int> p;
int match[maxn];

int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        if(a.empty()){
            a.push_back(make_pair(s[i],i));
            dep++;
            p.push_back(i);
            continue;
        }
        else{
            if(s[i]==')'&&a.back().first=='('){
                dp[a.back().second]=dep;
                match[a.back().second]=i;
                dep--;
                a.pop_back();
            }
            else{
                a.push_back(make_pair(s[i],i));
                dep++;
            }
        }
    }
       // printf("%d\n",match[1]);
    //printf("\n");
    for(int i=1;i<=n;i++)
    if(dp[i]&1){
        col[i]=1;
        col[match[i]]=1;
    }
    for(int i=1;i<=n;i++)
        printf("%d",col[i]);
}