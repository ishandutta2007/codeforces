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
    LL a,b,c;
    cin>>n>>m;
    vector<int> v1(n),v2(m);
    for(i=0;i<n;i++){
        cin>>v1[i];
        v1[i]--;
    }
    for(i=0;i<m;i++){
        cin>>v2[i];
    }
    sort(v1.begin(),v1.end());
    a=0;
    LL s=0;
    priority_queue<int,vector<int>,greater<int>> q1,q2;
    for(i=0;i<n;i++){
        for(;a<v1[i];a++)q1.push(v2[a]);
        q2.push(v2[v1[i]]);
        if(q1.empty())b=INF;
        else b=q1.top();
        c=q2.top();
        if(b<c)s+=b,q1.pop();
        else s+=c,q2.pop();
    }
    cout<<s<<endl;
}

int main(){
    int n,i;
    init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}