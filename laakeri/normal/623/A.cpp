#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int g[555][555];
int c[555];
int dg[555];

int n;

void dfs(int x, int co){
    if (c[x]>0){
        if (c[x]==co) return;
        else{
            cout<<"No"<<endl;
            exit(0);
        }
    }
    c[x]=co;
    for (int i=1;i<=n;i++){
        if (g[x][i]){
            dfs(i, 3-co);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        dg[i]=n-1;
        for (int ii=1;ii<=n;ii++){
            g[i][ii]=1;
        }
    }
    for (int i=1;i<=n;i++){
        g[i][i]=0;
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a][b]=0;
        g[b][a]=0;
        dg[a]--;
        dg[b]--;
    }
    int f=0;
    for (int i=1;i<=n;i++){
        if (dg[i]>0){
            if (c[i]==0){
                dfs(i, 1);
            }
        }
    }
    string v;
    for (int i=1;i<=n;i++){
        if (c[i]==0){
            v+='b';
        }
        else if(c[i]==1){
            v+='a';
        }
        else{
            v+='c';
        }
    }
    for (int i=1;i<=n;i++){
        for (int ii=1;ii<=n;ii++){
            if (i!=ii){
                if ((v[i-1]=='a'&&v[ii-1]=='c')||(v[i-1]=='c'&&v[ii-1]=='a')){
                    if (g[i][ii]==0||g[ii][i]==0){
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
                else{
                    if (g[i][ii]==1||g[ii][i]==1){
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    cout<<v<<endl;
}