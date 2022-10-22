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
typedef pair<LL,LL> LP;
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
template<typename T> ostream& operator<<(ostream& os,const vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++){
        if(i)os<<" ";
        os<<v1[i];
    }
    return os;
}
template<typename T1,typename T2> ostream& operator<<(ostream& os,const pair<T1,T2>& p){
    os<<p.first<<" "<<p.second;
    return os;
}
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}

namespace sol{
    int n,m;

    void init(){
        
    }

    void ans(vector<int>& v1){
        cout<<"!";
        for(auto num:v1){
            cout<<" "<<num;
        }
        cout<<endl;
    }

    int ques(int t,int i,int j,int x){
        assert(1<=x && x<=n-1);
        cout<<"? "<<t<<" "<<i+1<<" "<<j+1<<" "<<x<<endl;
        int s;
        cin>>s;
        return s;
    }

    void solve(){
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<int> v1(n/2),v2(n/2);
        vector<int> vs(n);
        for(i=0,j=0;i+1<n;i+=2,j++){
            v1[j]=ques(1,i,i+1,n-1);
            v2[j]=ques(2,i,i+1,1);
            if(v1[j]==n-1)v1[j]=ques(1,i+1,i,n-1);
            if(v2[j]==2)v2[j]=ques(2,i+1,i,1);
        }
        vector<char> used(n+1);
        if(n%2){
            for(i=0;i<n/2;i++){
                used[v1[i]]=1,used[v2[i]]=1;
            }
            a=-1;
            for(i=1;i<=n;i++){
                if(!used[i])a=i;
            }
            assert(a!=-1);
            vs[n-1]=a;
        }
        for(i=0,j=0;j<n/2;i+=2,j++){
            vs[i]=v1[j],vs[i+1]=v2[j];
            if(ques(1,i,i+1,v2[j])!=v2[j])swap(vs[i],vs[i+1]);
        }
        ans(vs);
    }
}

int main(){
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}