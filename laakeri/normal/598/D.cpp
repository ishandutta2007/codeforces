#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

string s[1010];
int cc[1010][1010];
int ccp[1010101];

int n,m;

void dfs1(int y, int x, int c){
    if (cc[y][x]>0) return;
    cc[y][x]=c;
    for (int i=-1;i<=1;i++){
        for (int ii=-1;ii<=1;ii++){
            if ((i==0)^(ii==0)){
                if (y+i<n&&y+i>=0&&x+ii<m&&x+ii>=0){
                    if (s[y+i][x+ii]=='*'){
                        ccp[c]++;
                    }
                    else{
                        dfs1(y+i, x+ii, c);
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }
    int ccs=1;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            if (cc[i][ii]==0&&s[i][ii]=='.'){
                dfs1(i, ii, ccs++);
            }
        }
    }
    for (int i=0;i<k;i++){
        int y,x;
        cin>>y>>x;
        y--;
        x--;
        cout<<ccp[cc[y][x]]<<'\n';
    }
}