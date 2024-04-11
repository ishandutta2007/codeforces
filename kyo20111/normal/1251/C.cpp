#include<bits/stdc++.h>
using namespace std;
int t;
char s[303030],re[303030];
stack<string> q;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);

        vector<pair<int,int>> v;
        for(int i=0;s[i];i++) v.push_back({s[i], i});
        sort(v.begin(),v.end(),greater<pair<int,int>>());

        int l = strlen(s);
        int mn[2]={l,l};


        for(pair<int,int> nxt : v){
            if(mn[nxt.first % 2] > nxt.second){
                int cnt = 0;
                for(int i=nxt.second;i<mn[nxt.first % 2];i++) if(s[i]%2 == nxt.first%2) re[cnt++] = s[i];
                re[cnt] = 0;
                q.push(re);
                mn[nxt.first % 2] = nxt.second;
            }
        }

        while(!q.empty()){
            printf("%s",q.top().data());
            q.pop();
        }
        puts("");
    }
}