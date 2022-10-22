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

vector<int> v1[110000];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    string sa;
    cin>>n>>m;
    cin>>sa;
    vector<char> used(n);
    for(i=0,j=0;i<sa.size();i++){
        if(sa[i]=='(')v1[j++].push_back(i);
        else v1[--j].push_back(i);
    }
    for(i=1e5,j=0;i>=0;i--){
        for(k=0;k<v1[i].size() && j<n-m;k++,j++){
            used[v1[i][k]]=1;
        }
    }
    string sb;
    for(i=0;i<sa.size();i++){
        if(used[i])continue;
        sb.push_back(sa[i]);
    }
    cout<<sb<<endl;
}