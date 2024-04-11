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
    LL n,m;
    int i,j,k;
    LL a,b,c,d;
    LL s=0,x=0;
    vector<P> v1;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(make_pair(0,((LL)i<<40)+a));
    }
    for(i=30;i>=0;i--){
        a=0,b=0,c=0,d=0;
        for(j=0;j<n;j++){
            if(j && v1[j-1].first<v1[j].first)b=0,d=0;
            if(v1[j].second&(1<<i))b++,c+=d,v1[j].first+=1<<i;
            else a+=b,d++;
        }
        if(c<a){
            s+=c,x+=1<<i;
        }else s+=a;
        sort(v1.begin(),v1.end());
    }
    cout<<s<<" "<<x<<endl;
}