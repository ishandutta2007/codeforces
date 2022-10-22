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
#include<unordered_map>
#include<unordered_set>
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

namespace sol{
    int n,m;
    map<int,int> ma;
    int ques(int pos){
        if(pos<0 || pos>=n)return INF;
        if(ma.find(pos)!=ma.end())return ma[pos];
        cout<<"? "<<pos+1<<endl;
        int s;
        cin>>s;
        ma[pos]=s;
        return s;
    }

    int ans(int pos){
        cout<<"! "<<pos+1<<endl;
    }

    void solve(){
        int i,j,k;
        int a,b,c;
        cin>>n;
        int z[3]={0,n};
        while(z[1]-z[0]>1){
            z[2]=(z[0]+z[1])/2;
            a=ques(z[2]-1);
            b=ques(z[2]);
            c=ques(z[2]+1);
            if(b<a && b<c){
                ans(z[2]);
                return;
            }
            if(a<b)z[1]=z[2];
            else z[0]=z[2]+1;
        }
        for(i=z[0]-3;i<=z[0]+3;i++){
            a=ques(i-1);
            b=ques(i);
            c=ques(i+1);
            if(b<a && b<c){
                ans(i);
                return;
            }
        }
        assert(false);
    }
}

int main(){
    sol::solve();
}