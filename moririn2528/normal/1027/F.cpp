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
    vector<P> vs;

    P pmax(P pa,P pb){
        if(pa.first<pb.first)swap(pa,pb);
        pa.second=max(pa.second,pb.first);
        return pa;
    }
public:
    void init(){
        uft_parent.assign(uft_n,-1);
        uft_num.assign(uft_n,1);
        vs.assign(uft_n,make_pair(-1,-1));
        for(int i=0;i<uft_n;i++){
            vs[i].first=i;
        }
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

    int check_max(int x){
        x=check_parent(x);
        return vs[x].second;
    }

    bool connect(int uft_x,int uft_y){
        assert(uft_x>=0 && uft_x<uft_n);
        assert(uft_y>=0 && uft_y<uft_n);
        uft_x=check_parent(uft_x),uft_y=check_parent(uft_y);
        if(uft_x==uft_y){
            swap(vs[uft_x].first,vs[uft_x].second);
            vs[uft_x].first=INF;
            return true;
        }
        if(uft_num[uft_x]>uft_num[uft_y])swap(uft_x,uft_y);
        uft_parent[uft_x]=uft_y;
        uft_num[uft_y]+=uft_num[uft_x];
        vs[uft_y]=pmax(vs[uft_y],vs[uft_x]);
        return false;
    }

    int size(int pos){
        pos=check_parent(pos);
        return uft_num[pos];
    }
};

map<int,int> m1;

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    scanf("%d",&n);
    vector<P> v1;
    vector<int> va;
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        v1.push_back(make_pair(a,b));
        m1[a]=0,m1[b]=0;
    }
    i=0;
    for(auto& node:m1){
        node.second=i++;
        va.push_back(node.first);
    }
    m=va.size();
    union_find_tree ua(m);
    for(i=0;i<n;i++){
        ua.connect(m1[v1[i].first],m1[v1[i].second]);
    }
    a=0;
    for(i=0;i<m;i++){
        a=max(a,ua.check_max(i));
    }
    if(a>=INF){
        cout<<-1<<endl;
    }else{
        cout<<va[a]<<endl;
    }
}