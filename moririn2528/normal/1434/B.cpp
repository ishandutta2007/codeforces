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

priority_queue<int,vector<int>,greater<int>> q1;
vector<int> vs;

bool solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    char ca;
    cin>>n;
    vector<int> v1;
    for(i=0;i<2*n;i++){
        cin>>ca;
        if(ca=='+'){
            v1.push_back(-1);
        }else{
            cin>>a;
            v1.push_back(a);
        }
    }
    reverse(v1.begin(),v1.end());
    for(i=0;i<2*n;i++){
        if(v1[i]!=-1){
            if(!q1.empty() && q1.top()<v1[i])return false;
            q1.push(v1[i]);
            continue;
        }
        if(q1.empty())return false;
        a=q1.top();q1.pop();
        vs.push_back(a);
    }
    reverse(vs.begin(),vs.end());
    return true;
}

int main(){
    if(solve()){
        cout<<"YES"<<endl;
        array_show(vs);
    }else cout<<"NO"<<endl;
}