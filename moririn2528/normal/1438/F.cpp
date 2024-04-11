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
#include<random>
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

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    random_device engine;
    mt19937 rand(engine());
    map<int,int> m1;
    cin>>m;
    n=(1<<m)-1;
    for(i=0;i<420;i++){
        vector<int> v1(3,0);
        while(v1[0]==v1[1] || v1[1]==v1[2] || v1[2]==v1[0]){
            for(j=0;j<3;j++){
                v1[j]=rand()%n;
            }
        }
        cout<<"?";
        for(j=0;j<3;j++){
            cout<<" "<<v1[j]+1;
        }
        cout<<endl;
        cin>>a;
        a--;
        m1[a]++;
    }
    vector<P> v2;
    for(auto node:m1){
        v2.push_back(make_pair(node.second,node.first));
    }
    sort(v2.rbegin(),v2.rend());
    assert(v2.size()>=2);
    a=v2[0].second,b=v2[1].second;
    m1.clear();
    for(i=0;i<n;i++){
        if(a==i || b==i)continue;
        cout<<"? "<<a+1<<" "<<b+1<<" "<<i+1<<endl;
        cin>>c;
        c--;
        m1[c]++;
    }
    for(auto node:m1){
        if(node.second==1){
            cout<<"! "<<node.first+1<<endl;
            return 0;
        }
    }
}