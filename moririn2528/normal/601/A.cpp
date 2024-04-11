#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
#include<complex>
#include<numeric>
#include<functional>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

bool t[444][444];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    bool flag=false;
    cin>>n>>m;
    vector<vector<int>> path(n);
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        if(a>b)swap(a,b);
        if(a==0 && b==n-1)flag=true;
        path[a].push_back(b);
        path[b].push_back(a);
        t[a][b]=true;
    }
    if(flag){
        path.assign(n,vector<int>());
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(t[i][j])continue;
                path[i].push_back(j);
                path[j].push_back(i);
            }
        }
    }
    queue<int> q1;
    vector<char> used(n);
    q1.push(0);
    for(i=0;!q1.empty();i++){
        j=q1.size();
        while(j--){
            a=q1.front();q1.pop();
            if(a==n-1){
                cout<<i<<endl;
                return 0;
            }
            if(used[a])continue;
            used[a]=true;
            for(auto to:path[a]){
                q1.push(to);
            }
        }
    }
    cout<<-1<<endl;
}