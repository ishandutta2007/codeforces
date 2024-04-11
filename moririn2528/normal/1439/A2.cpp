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

void init(){
    
}

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    string sa;
    cin>>n>>m;
    vector<vector<char>> used(n,vector<char>(m));
    vector<P> vs;
    for(i=0;i<n;i++){
        cin>>sa;
        for(j=0;j<m;j++){
            if(sa[j]=='1')used[i][j]=1;
        }
    }
    for(i=0;i<n;i+=2){
        if(i==n-1)i=n-2;
        for(j=0;j<m-2;j++){
            if(used[i][j]){
                vs.push_back(make_pair(i,j));
                used[i][j]=0;
            }
            if(used[i+1][j]){
                vs.push_back(make_pair(i+1,j));
                used[i+1][j]=0;
            }
            if(vs.size()%3==0)continue;
            used[i][j+1]=!used[i][j+1];
            vs.push_back(make_pair(i,j+1));
            if(vs.size()%3==0)continue;
            used[i+1][j+1]=!used[i+1][j+1];
            vs.push_back(make_pair(i+1,j+1));
        }
    }
    j=m-2;
    for(i=0;i<n-2;i++){
        if(used[i][j]){
            vs.push_back(make_pair(i,j));
            used[i][j]=0;
        }
        if(used[i][j+1]){
            vs.push_back(make_pair(i,j+1));
            used[i][j+1]=0;
        }
        if(vs.size()%3==0)continue;
        used[i+1][j]=!used[i+1][j];
        vs.push_back(make_pair(i+1,j));
        if(vs.size()%3==0)continue;
        used[i+1][j+1]=!used[i+1][j+1];
        vs.push_back(make_pair(i+1,j+1));
    }
    for(i=0;i<10;i++){
        a=0;
        for(j=n-2;j<n;j++){
            for(k=m-2;k<m;k++){
                if(used[j][k])a++;
            }
        }
        if(a==0)break;
        if(a<=2)a=1,b=2;
        else a=3,b=0;
        for(j=n-2;j<n;j++){
            for(k=m-2;k<m;k++){
                if(used[j][k] && a>0){
                    used[j][k]=!used[j][k];
                    vs.push_back(make_pair(j,k));
                    a--;
                }else if(!used[j][k] && b>0){
                    used[j][k]=!used[j][k];
                    vs.push_back(make_pair(j,k));
                    b--;
                }
            }
        }
        assert(vs.size()%3==0);
    }
    assert(a==0);
    assert(vs.size()%3==0);
    cout<<vs.size()/3<<endl;
    for(i=0;i<vs.size();i+=3){
        for(j=0;j<3;j++){
            if(j)cout<<" ";
            cout<<vs[i+j].first+1<<" "<<vs[i+j].second+1;
        }
        cout<<endl;
    }
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}