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
const LL INF=1LL<<40;
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

    vector<vector<LP>> path;
    typedef tuple<LL,LL,LL> T;
    vector<char> used;
    vector<LL> vc;

    bool dfs1(int pos,int en,vector<T>& v1){
        if(pos==en)return true;
        if(used[pos])return false;
        used[pos]=1;
        for(auto node:path[pos]){
            int to=node.first,id=node.second;
            if(used[to])continue;
            v1.push_back({pos,to,id});
            if(dfs1(to,en,v1))return true;
            v1.pop_back();
        }
        return false;
    }

    LL dfs2(int pos,int bef_id,int y,int& cnt,vector<int>& ord,vector<int>& lowlink){
        if(ord[pos]!=-1)return -1;
        lowlink[pos]=ord[pos]=cnt++;
        LL s=INF;
        for(auto node:path[pos]){
            int to=node.first,id=node.second;
            if(id==bef_id)continue;
            LL a=dfs2(to,id,y,cnt,ord,lowlink);
            if(a==-1){
                lowlink[pos]=min(lowlink[pos],ord[to]);
            }else{
                lowlink[pos]=min(lowlink[pos],lowlink[to]);
                if(a<=vc.size()){
                    s=a;
                    if(lowlink[to]>ord[pos] && (s==vc.size() || vc[s]>vc[id]))s=id;
                }
            }
        }
        if(pos==y)return vc.size();
        return s;
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        int x,y,z;
        cin>>n>>m;
        cin>>x>>y;
        x--,y--;
        path.resize(n);
        for(i=0;i<m;i++){
            cin>>a>>b>>c;
            a--,b--;
            path[a].push_back({b,i});
            path[b].push_back({a,i});
            vc.push_back(c);
        }
        used.assign(n,0);
        vector<T> vt;
        vector<int> vs;
        if(!dfs1(x,y,vt)){
            cout<<0<<endl;
            cout<<0<<endl;
            return;
        }
        LL s=INF;
        for(auto e:vt){
            int id;
            tie(a,b,id)=e;
            auto func_erase=[&](int pos){
                for(auto& node:path[pos]){
                    if(node.second==id){
                        swap(node,path[pos].back());
                        path[pos].pop_back();
                        break;
                    }
                }
            };
            func_erase(a),func_erase(b);
            vector<int> ord(n,-1),lowlink(n,-1);
            z=0;
            c=dfs2(x,-1,y,z,ord,lowlink);
            if(c==INF && s>vc[id]){
                s=vc[id];
                vs={id+1};
            }
            if(c<m && vc[id]+vc[c]<s){
                s=vc[id]+vc[c];
                vs={id+1,(int)c+1};
            }
            path[a].push_back({b,id});
            path[b].push_back({a,id});
        }
        if(s==INF){
            cout<<-1<<endl;
            return;
        }
        cout<<s<<endl;
        cout<<vs.size()<<endl;
        cout<<vs<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}