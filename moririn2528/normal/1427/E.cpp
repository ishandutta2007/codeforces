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

vector<tuple<LL,LL,int>> vs;

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    a=n;
    vs.push_back(make_tuple(a,a,0));
    b=a*2;
    if(a&2){
        vs.push_back(make_tuple(a,b,1));
        a^=b;
    }
    b=a;
    for(i=1;(1LL<<i)<=a;i++){
        vs.push_back(make_tuple(b,b,0));
        b*=2;
    }
    vs.push_back(make_tuple(a,b,0));
    vs.push_back(make_tuple(a,b,1));
    vs.push_back(make_tuple(a+b,a^b,1));
    for(j=i;j>0;j--){
        a=1LL<<j;
        if(n&a){
            vs.push_back(make_tuple(n,a,1));
            n^=a;
        }
        b=n;
        for(k=0;k<j-1;k++){
            vs.push_back(make_tuple(b,b,0));
            b*=2;
            if(b&a){
                vs.push_back(make_tuple(b,a,1));
                b^=a;
            }
        }
    }

    cout<<vs.size()<<endl;
    for(auto node:vs){
        tie(a,b,c)=node;
        cout<<a<<" ";
        if(c==0)cout<<"+";
        else cout<<"^";
        cout<<" "<<b<<endl;
    }
}