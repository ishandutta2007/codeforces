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
    string s;

    void set1(int i,int j){
        i=max(i,0);
        j=min(j,n);
        for(int k=i;k<j;k++){
            s[k]='1';
        }
    }

    void set2(int a,int b){
        if((b-a)%2){
            set1(a,(a+b)/2);
            set1((a+b)/2+1,b);
        }else{
            set1(a,b);
        }
    }

    void solve(){
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        cin>>s;
        a=-1;
        for(i=0;i<n;i++){
            if(s[i]=='0')continue;
            if(a==-1){
                set1(i-m,i);
                a=i;
                continue;
            }
            if(2*m<i-a){
                set1(a+1,a+m+1);
                set1(i-m,i);
            }else{
                set2(a+1,i);
            }
            a=i;
        }
        if(a!=-1)set1(a+1,a+m+1);
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}