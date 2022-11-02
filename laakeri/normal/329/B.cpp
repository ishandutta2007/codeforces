#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

string s[1010];
int used[1010][1010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r,c;
    cin>>r>>c;
    for (int i=0;i<r;i++){
        cin>>s[i];
    }
    int f=1e9;
    queue<pair<pair<int, int>, int> > bfs;
    for (int i=0;i<r;i++){
        for (int ii=0;ii<c;ii++){
            if (s[i][ii]=='E') bfs.push({{i, ii}, 0});
        }
    }
    int v=0;
    while (!bfs.empty()){
        auto x=bfs.front();
        bfs.pop();
        if (x.S<=f){
            int i=x.F.F;
            int ii=x.F.S;
            if (i>=0&&i<r&&ii>=0&&ii<c){
                if (!used[i][ii]){
                    used[i][ii]=1;
                    if (s[i][ii]!='T'){
                        if (s[i][ii]=='S'){
                            f=x.S;
                        }
                        if (s[i][ii]>='0'&&s[i][ii]<='9'){
                            v+=s[i][ii]-'0';
                        }
                        bfs.push({{i+1, ii}, x.S+1});
                        bfs.push({{i-1, ii}, x.S+1});
                        bfs.push({{i, ii+1}, x.S+1});
                        bfs.push({{i, ii-1}, x.S+1});
                    }
                }
            }
        }
    }
    cout<<v<<endl;
}