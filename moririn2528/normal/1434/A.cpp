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

vector<int> v1,v2;
priority_queue<P,vector<P>,greater<P>> q1;

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    set<int> s1;
    for(i=0;i<6;i++){
        cin>>a;
        if(s1.find(a)!=s1.end())continue;
        s1.insert(a);
        v1.push_back(a+1);
    }
    sort(v1.begin(),v1.end());
    b=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        v2.push_back(a);
        q1.push(make_pair(a-v1.back(),v1.size()-1));
        b=max(b,a-v1.back());
    }
    int s=INF;
    while(!q1.empty()){
        a=q1.top().first,c=q1.top().second,q1.pop();
        s=min(s,b-a);
        if(c==0)break;
        a+=v1[c]-v1[c-1];
        q1.push(make_pair(a,c-1));
        b=max(a,b);
    }
    cout<<s<<endl;
}