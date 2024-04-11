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

class union_find_tree{
private:
    static constexpr int N=100005;
    int n;
    queue<int> q1;
    vector<int> parent;
    vector<int> num;
public:
    void init(){
        parent.assign(n,-1);
        num.assign(n,1);
    }
    union_find_tree(int n_init){
        assert(n_init>=0);
        n=n_init;
        init();
    }
    union_find_tree(){
        n=N;
        init();
    }

    int check_parent(int x){
        assert(x>=0 && x<n);
        if(parent[x]!=-1){
            q1.push(x);
            return check_parent(parent[x]);
        }
        int a;
        while(!q1.empty()){
            a=q1.front(),q1.pop();
            parent[a]=x;
        }
        return x;
    }

    bool connect(int x,int y){
        assert(x>=0 && x<n);
        assert(y>=0 && y<n);
        x=check_parent(x),y=check_parent(y);
        if(x==y)return true;
        if(num[x]>num[y])swap(x,y);
        parent[x]=y;
        num[y]+=num[x];
        return false;
    }

    int size(int pos){
        pos=check_parent(pos);
        return num[pos];
    }

    bool check(int x,int y){//connect:true
        assert(x>=0 && x<n);
        assert(y>=0 && y<n);
        return check_parent(x)==check_parent(y);
    }
};

namespace sol{

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        union_find_tree ua(n);
        vector<int> v1(n),v2;
        cin>>v1;
        for(i=0,b=-1;i<n;i++){
            v1[i]--;
            a=v1[i];
            if(ua.connect(i,a))v2.push_back(i);
            if(i==a)b=i;
        }
        int s=v2.size();
        if(b!=-1)s--;
        else if(!v2.empty())b=v2[0];
        for(auto num:v2){
            v1[num]=b;
        }
        for(auto& num:v1)num++;
        cout<<s<<endl;
        cout<<v1<<endl;

    }
}

int main(){
    sol::solve();
}