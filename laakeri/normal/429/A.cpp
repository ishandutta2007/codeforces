#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100001];
vector<int> flip;

int a[100001];
int t[100001];

int v=0;

void dfs (int x,int edx,int oddc,int evenc,int isodd){
    //cout <<x<<" "<<edx<<" "<<oddc<<" "<<evenc<<" "<<isodd<<endl;
    if (isodd){
        if ((oddc^a[x])!=t[x]){
            v++;
            flip.push_back(x);
            oddc=!oddc;
        }
    }
    else {
        if ((evenc^a[x])!=t[x]){
            v++;
            flip.push_back(x);
            evenc=!evenc;
        }
    }
    for (int nx:g[x]){
        if (nx!=edx){
            dfs(nx,x,oddc,evenc,!isodd);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=0;i<n;i++)cin>>a[i+1];
    for (int i=0;i<n;i++)cin>>t[i+1];
    dfs (1,0,0,0,0);
    cout <<v<<endl;
    for (int i=0;i<flip.size();i++){
        cout<<flip[i]<<'\n';
    }
}