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
template<typename T1,typename T2> istream& operator>>(istream& is,pair<T1,T2>& p){
    is>>p.first>>p.second;
    return is;
}

namespace sol{

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        double da,db;
        cin>>n>>m;
        vector<LL> vt(n);
        cin>>vt;
        vector<vector<LL>> vm;
        vector<pair<double,int>> vma;
        vector<int> vmi(m);
        sort(vt.rbegin(),vt.rend());
        while(vt.size()>m)vt.pop_back();
        reverse(vt.begin(),vt.end());
        for(i=0;i<m;i++){
            cin>>a;
            vector<LL> va(a);
            cin>>va;
            vm.push_back(va);
            b=0;
            for(auto num:va){
                b+=num;
            }
            vma.push_back({(double)b/a,i});
        }
        sort(vma.begin(),vma.end());
        for(i=0;i<m;i++){
            a=vma[i].second;
            vmi[a]=i;
        }
        vector<int> v1(m+1),v2(m+1),v3(m+1);
        for(i=0;i<m;i++){
            v1[i+1]=v1[i],v2[i+1]=v2[i],v3[i+1]=v3[i];
            v1[i+1]+=vma[i].first<=vt[i]?0:1;
            if(i+1<m){
                v2[i+1]+=vma[i+1].first<=vt[i]?0:1;
                v3[i+1]+=vma[i].first<=vt[i+1]?0:1;
            }
        }
        string ss;
        for(i=0;i<m;i++){
            a=vmi[i];
            b=0;
            for(auto num:vm[i])b+=num;
            for(auto num:vm[i]){
                da=(double)(b-num)/(vm[i].size()-1);
                auto itr=lower_bound(vma.begin(),vma.end(),pair<double,int>(da,-1));
                c=itr-vma.begin();
                if(a<c){
                    c--;
                    if(v1[a]==0 && v2[c]-v2[a]==0 && da<=vt[c] && v1[m]-v1[c+1]==0){
                        ss.push_back('1');
                    }else ss.push_back('0');
                    continue;
                }
                if(v1[c]==0 && v3[a]-v3[c]==0 && da<=vt[c] && v1[m]-v1[a+1]==0){
                    ss.push_back('1');
                }else ss.push_back('0');

            }
        }
        cout<<ss<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}