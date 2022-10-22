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

vector<int> v1;

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    vector<int> va={1},vb={0,1};
    for(i=0;i<n-1;i++){
        vector<int> vc(i+3);
        for(j=0;j<i+3;j++){
            if(j<va.size())vc[j]=va[j];
            if(j>0)vc[j]+=vb[j-1];
            vc[j]%=2;
        }
        swap(va,vb);
        vb=vc;
    }
    cout<<vb.size()-1<<endl;
    array_show(vb);
    cout<<va.size()-1<<endl;
    array_show(va)
    ;
}