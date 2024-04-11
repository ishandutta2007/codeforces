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

int t[110000];
vector<P> vs;

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    vector<int> v1,v2;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t[i];
    }
    for(i=n-1;i>=0;i--){
        if(t[i]==0)continue;
        if(t[i]==2){
            if(v1.empty()){
                cout<<-1<<endl;
                return 0;
            }
            a=v1.back();
            v1.pop_back();
            vs.push_back(make_pair(a+1,i+1));
            v2.push_back(i);
            continue;
        }
        if(t[i]==3){
            if(v1.empty() && v2.empty()){
                cout<<-1<<endl;
                return 0;
            }
            if(v2.empty()){
                a=v1.back();
                v1.pop_back();
            }else{
                a=v2.back();
                v2.pop_back();
            }
            vs.push_back(make_pair(i+1,i+1));
            vs.push_back(make_pair(i+1,a+1));
            v2.push_back(i);
            continue;
        }
        vs.push_back(make_pair(i+1,i+1));
        v1.push_back(i);
    }
    cout<<vs.size()<<endl;
    for(auto node:vs){
        cout<<node.first<<" "<<node.second<<endl;
    }
}