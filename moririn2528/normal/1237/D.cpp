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
void array_show(vector<int> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%d%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%lld%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}

map<int,int> m1;
vector<P> v1;
int num[100005];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(make_pair(a,i));
    }
    sort(v1.begin(),v1.end());
    for(i=0,j=0;i<v1.size();i++){
        for(;v1[j].first*2<v1[i].first;j++){
            a=v1[j].second;
            m1[a]=1;
        }
        a=v1[i].second;
        if(m1.size()==0){
            num[a]=INF;
            continue;
        }
        auto itr=m1.upper_bound(a);
        if(itr==m1.end())num[a]=m1.begin()->first+n-a;
        else num[a]=itr->first-a;
    }
    a=INF;
    for(i=2*n-1;i>=0;i--){
        j=i%n;
        num[j]=min(a,num[j]);
        a=num[j]+1;
    }
    for(i=0;i<n;i++){
        if(num[i]==INF)num[i]=-1;
    }
    array_show(num,n);
}