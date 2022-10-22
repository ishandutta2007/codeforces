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

int check(int pos,vector<int>& path,vector<int>& cnt,vector<int>& val){
    if(cnt[pos]==0)return 1e9;
    cnt[pos]=0;
    return min(check(path[pos],path,cnt,val),val[pos]);
}

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n;
    vector<int> cnt(n),path(n),val(n);
    queue<int> q1;
    for(i=0;i<n;i++){
        cin>>val[i];
    }
    for(i=0;i<n;i++){
        cin>>path[i];
        path[i]--;
        cnt[path[i]]++;
    }
    for(i=0;i<n;i++){
        if(cnt[i]==0)q1.push(i);
    }
    while(!q1.empty()){
        a=q1.front(),q1.pop();
        cnt[path[a]]--;
        if(cnt[path[a]]==0)q1.push(path[a]);
    }
    a=0;
    for(i=0;i<n;i++){
        if(cnt[i]==0)continue;
        a+=check(i,path,cnt,val);
    }
    cout<<a<<endl;
}