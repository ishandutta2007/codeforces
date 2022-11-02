#include <iostream>
#include <vector>

using namespace std;

vector<int> ds[100002];
int fo[100002];
int fs=0;

int n,k;

vector<pair<int,int> > va;

void dfs (int x,int d,int ed){
    fs++;
    if (ed!=-1){
        va.push_back(make_pair(ed,x));
    }
    int co=k-1;
    if (ed==-1) co=k;
    for (int i=fo[d+1];i<ds[d+1].size();i++){
        if (co<=0) break;
        dfs (ds[d+1][i],d+1,x);
        fo[d+1]++;
        co--;
    }
}

int main(){
    cin>>n>>k;
    int r=0;
    int f=0;
    for (int i=0;i<n;i++){
        int di;
        cin>>di;
        if (di==0){
            r=i;
            f=1;
        }
        ds[di].push_back(i);
    }
    if (!f){
        cout <<"-1"<<endl;
        return 0;
    }
    dfs (r,0,-1);
    if (fs<n){
        cout <<"-1"<<endl;
        return 0;
    }
    cout <<va.size()<<endl;
    for (auto vas:va){
        cout <<vas.first+1<<" "<<vas.second+1<<endl;
    }
}