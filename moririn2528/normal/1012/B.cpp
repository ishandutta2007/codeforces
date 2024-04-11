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

class union_find_tree{
private:
    static constexpr int uft_N=100005;
    int uft_n;
    queue<int> uft_q1;
    vector<int> uft_parent;
    vector<int> uft_num;
public:
    void init(){
        uft_parent.assign(uft_n,-1);
        uft_num.assign(uft_n,1);
    }
    union_find_tree(int uft_n_init){
        assert(uft_n_init>=0);
        uft_n=uft_n_init;
        init();
    }
    union_find_tree(){
        uft_n=uft_N;
        init();
    }

    int check_parent(int uft_x){
        assert(uft_x>=0 && uft_x<uft_n);
        if(uft_parent[uft_x]!=-1){
            uft_q1.push(uft_x);
            return check_parent(uft_parent[uft_x]);
        }
        int uft_a;
        while(!uft_q1.empty()){
            uft_a=uft_q1.front(),uft_q1.pop();
            uft_parent[uft_a]=uft_x;
        }
        return uft_x;
    }

    bool connect(int uft_x,int uft_y){
        assert(uft_x>=0 && uft_x<uft_n);
        assert(uft_y>=0 && uft_y<uft_n);
        uft_x=check_parent(uft_x),uft_y=check_parent(uft_y);
        if(uft_x==uft_y)return true;
        if(uft_num[uft_x]>uft_num[uft_y])swap(uft_x,uft_y);
        uft_parent[uft_x]=uft_y;
        uft_num[uft_y]+=uft_num[uft_x];
        return false;
    }

    int size(int pos){
        pos=check_parent(pos);
        return uft_num[pos];
    }
};

int main(){
    int n,m,p;
    int i,j,k;
    int a,b,c;
    cin>>n>>m>>p;
    c=n+m-1;
    union_find_tree ua(n+m);
    for(i=0;i<p;i++){
        cin>>a>>b;
        a--,b--;
        b+=n;
        if(!ua.connect(a,b))c--;
    }
    cout<<c<<endl;
}