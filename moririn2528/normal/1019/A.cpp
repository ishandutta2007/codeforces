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
typedef pair<LL,LL> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;
typedef tuple<LL,int,int> T;

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

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n>>m;
    vector<vector<LL>> v1(m);
    vector<P> v2(n+10);
    for(i=0;i<n;i++){
        cin>>a>>b;
        a--;
        v1[a].push_back(b);
    }
    for(i=0;i<m;i++){
        sort(v1[i].rbegin(),v1[i].rend());
        a=0,b=0;
        if(i==0)continue;
        for(j=(int)v1[i].size()-1;j>=0;j--){
            a+=v1[i][j],b++;
            v2[j].first+=a,v2[j].second+=b;
        }
    }
    LL s=(LL)1<<60;
    int x,y;
    for(i=0;i<n;i++){
        a=v2[i].first,b=v1[0].size()+v2[i].second;
        if(b>=i+1){
            s=min(s,a);
            continue;
        }
        priority_queue<T,vector<T>,greater<T>> q1;  
        for(j=1;j<m;j++){
            if(v1[j].size()>i-1)q1.push(make_tuple(v1[j][i-1],j,i-1));
            else if(v1[j].size()>0)q1.push(make_tuple(v1[j].back(),j,(int)v1[j].size()-1));
        }
        for(j=0;j<i+1-b;j++){
            tie(c,x,y)=q1.top();
            q1.pop();
            a+=c;
            if(y>0)q1.push(make_tuple(v1[x][y-1],x,y-1));
        }
        s=min(s,a);
    }
    cout<<s<<endl;
}