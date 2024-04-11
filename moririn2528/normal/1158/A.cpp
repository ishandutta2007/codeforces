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

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n>>m;
    vector<int> v1,v2;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    for(i=0;i<m;i++){
        cin>>a;
        v2.push_back(a);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1.back()>v2[0]){
        cout<<-1<<endl;
        return 0;
    }
    a=0;
    for(i=0;i<n-1;i++){
        a+=v1[i];
    }
    a*=m;
    if(v1.back()<v2[0])a+=v1[n-1]-v1[n-2];
    for(i=0;i<m;i++){
        a+=v2[i];
    }
    cout<<a<<endl;
}