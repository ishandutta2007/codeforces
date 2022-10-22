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

template<typename T> class Compress{
    //Compress<int> ca({5,1,2,3});
    //ca.id(5) //=3
private:
    vector<T> vec;
    vector<int> id_perm;//v1 index -> vec index
public:
    void init(const vector<T>& v1){
        int n=v1.size();
        int i,j;
        id_perm.assign(n,-1);
        vector<pair<T,int>> va;
        for(i=0;i<n;i++){
            va.push_back({v1[i],i});
        }
        sort(va.begin(),va.end());
        vec.clear();
        for(i=0,j=-1;i<n;i++){
            if(vec.empty() || vec.back()!=va[i].first){
                vec.push_back(va[i].first);
                j++;
            }
            id_perm[va[i].second]=j;
        }
    }

    Compress(const vector<T> v1){
        init(v1);
    }

    vector<int> get_id_perm()const{
        return id_perm;
    }

    int id(const T a){
        auto itr=lower_bound(vec.begin(),vec.end(),a);
        assert(itr!=vec.end());//return -1?
        assert(*itr==a);
        return itr-vec.begin();
    }
};

namespace sol{

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        cin>>n>>m;
        map<LL,LL> m1;
        vector<LL> v1(n),v2;
        cin>>v1;
        Compress<LL> ca(v1);
        for(i=0;i<n;i++){
            m1[v1[i]]++;
        }
        vector<LL> used(n,-1);
        vector<vector<LL>> vt(n);
        vector<vector<LP>> vp(n+1);
        LL s=0;
        for(auto node:m1){
            a=node.first,b=node.second;
            if(vp[b].empty())v2.push_back(b);
            vp[b].push_back({a,ca.id(a)});
        }
        for(i=0;i<m;i++){
            cin>>a>>b;
            a=ca.id(a);
            b=ca.id(b);
            vt[a].push_back(b);
            vt[b].push_back(a);
        }
        for(auto num:v2){
            sort(vp[num].rbegin(),vp[num].rend());
        }
        for(auto node:m1){
            a=node.first,b=node.second;
            c=ca.id(a);
            for(auto num:vt[c]){
                used[num]=a;
            }
            used[c]=a;
            for(auto z:v2){
                for(auto nums:vp[z]){
                    int p=nums.first,id=nums.second;
                    if((a+p)*(b+z)<=s)break;
                    if(used[id]==a)continue;
                    s=max(s,(a+p)*(b+z));
                }
            }
        }
        cout<<s<<endl;
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