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

set<P> s1;

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    vector<int> v1;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        s1.insert(make_pair(a,b));
        s1.insert(make_pair(b,a));
    }
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    if(v1[0]!=1){
        cout<<"No"<<endl;
        return 0;
    }
    a=0;
    for(i=1;i<n;i++){
        for(;a<i;a++){
            if(s1.find(make_pair(v1[a],v1[i]))!=s1.end())break;
        }
        if(a>=i){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}