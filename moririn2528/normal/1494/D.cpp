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
#include<unordered_map>
#include<unordered_set>
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

namespace sol{
    int n,m;
    int t[555][555];
    vector<P> path;
    vector<int> vs;

    int calc(vector<int>& v1){
        int a=0,b;
        int i,j,k;
        int x,y;
        if(v1.size()==1){
            a=v1[0];
            vs[a]=t[a][a];
            return a;
        }
        for(auto num:v1){
            a=max(a,t[num][v1[0]]);
        }
        int r=m++;
        vs.push_back(a);
        int p=v1.size();
        vector<char> used(p);
        for(i=0;i<p;i++){
            if(used[i])continue;
            vector<int> v2;
            for(j=0;j<p;j++){
                x=v1[i],y=v1[j];
                if(t[x][y]==a)continue;
                v2.push_back(y);
                used[j]=true;
            }
            b=calc(v2);
            path.push_back(make_pair(b,r));
        }
        return r;
    }

    void solve(){
        int i,j,k;
        int a,b,c;
        cin>>n;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>t[i][j];
            }
        }
        m=n;
        vector<int> v1;
        for(i=0;i<n;i++){
            v1.push_back(i);
        }
        vs.assign(n,0);
        int r=calc(v1);
        cout<<m<<endl;
        array_show(vs);
        cout<<r+1<<endl;
        for(auto node:path){
            cout<<node.first+1<<" "<<node.second+1<<endl;
        }
    }
}

int main(){
    sol::solve();
}