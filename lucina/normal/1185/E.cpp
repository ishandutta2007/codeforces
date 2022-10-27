#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int T,n,m;
char s[2005][2005];
bool vis[2005][2005];
struct ans{
    int x,y,z,w;
    ans(int _x,int _y,int _z,int _w):
        x(_x),y(_y),z(_z),w(_w){}
};
bool cmp(pair<int,int> p1,pair<int,int> p2){
    return p2.second==p1.second?p1.first<p2.first:p1.second<p2.second;
}

int main(){
    scanf("%d",&T);
    while(T--){
            vector<pair<int,int>> p[26];
            vector<ans> a;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            vis[i][j]=false;
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
            bool ch=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i][j]!='.'){
                    p[s[i][j]-'a'].emplace_back(i,j);
                    if((int)p[s[i][j]-'a'].size()>max(n,m)){
                        ch=false;
                        break;
                        }
                }
            }
        }
        pair<int,int> last;
        last.first=-1;
        for(int i=25;i>=0;i--){
            if(!p[i].empty()){
                    last=p[i][0];
                if(p[i].size()==1){
                    a.emplace_back(p[i][0].first,p[i][0].second,p[i][0].first,p[i][0].second);
                    vis[p[i][0].first][p[i][0].second]=true;
                }
                else{
                    if(p[i][1].first==p[i][0].first){
                        sort(p[i].begin(),p[i].end(),cmp);
                        for(auto j:p[i]){
                            vis[j.first][j.second]=true;
                            ch&=(j.first==p[i][0].first);
                        }
                        if(!ch)break;
                        for(int j=p[i][0].second;j<=p[i].back().second;j++){
                            ch&=(vis[p[i][0].first][j]);
                        }
                        if(ch){
                            a.emplace_back(p[i][0].first,p[i][0].second,p[i].back().first,p[i].back().second);
                        }
                    }
                    else if(p[i][1].second==p[i][0].second){
                        sort(p[i].begin(),p[i].end());
                        for(auto j:p[i]){
                            vis[j.first][j.second]=true;
                            ch&=(j.second==p[i][0].second);
                        }
                        if(!ch)break;
                        for(int j=p[i][0].first;j<=p[i].back().first;j++){
                            ch&=(vis[j][p[i][0].second]);
                        }
                        if(ch){
                            a.emplace_back(p[i][0].first,p[i][0].second,p[i].back().first,p[i].back().second);
                        }
                    }
                    else{
                        ch=false;
                        break;
                    }

                }
            }
        else{
            if(last.first!=-1)
        a.emplace_back(last.first,last.second,last.first,last.second);
        }
        }
         if(ch){
                    printf("YES\n");
                    printf("%d\n",(int)a.size());
                    for(auto it=a.rbegin();it!=a.rend();++it){
                        printf("%d %d %d %d\n",it->x,it->y,it->z,it->w);
                    }
                }
                else{
                    printf("NO\n");
                }
    }
}
/*
    Good Luck
         -Lucina
*/