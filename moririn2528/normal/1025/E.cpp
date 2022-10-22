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

typedef tuple<int,int,int,int> T;
vector<T> vs;

void move(P pos,P to,int cnt){
    for(int i=0;i<cnt;i++){
        T ta;
        ta=make_tuple(pos.first+1,pos.second+1,pos.first+to.first+1,pos.second+to.second+1);
        vs.push_back(ta);
        pos.first+=to.first,pos.second+=to.second;
    }
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c,d;
    P pa,pb;
    cin>>n>>m;
    vector<P> pos1(m),pos2(m),pos3(m);
    vector<P> v1,v2;
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        pos1[i]=make_pair(a,b);
        v1.push_back(make_pair(a,i));
    }
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        pos2[i]=make_pair(a,b);
        v2.push_back(make_pair(b,i));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(i=0;i<m;i++){
        pos3[v1[i].second].first=i;
        pos3[v2[i].second].second=i;
    }
    vector<vector<P>> va(n),vb(n);
    for(i=0;i<m;i++){
        va[pos1[i].second].push_back(make_pair(pos1[i].first,i));
        vb[pos2[i].first].push_back(make_pair(pos2[i].second,i));
    }
    for(i=0;i<n;i++){
        sort(va[i].begin(),va[i].end());
        sort(vb[i].begin(),vb[i].end());
    }
    vector<int> vt;
    for(i=0;i<n;i++){
        for(j=0;j<va[i].size();j++){
            a=va[i][j].second;
            if(pos1[a].first<pos3[a].first)vt.push_back(a);
            else{
                while(!vt.empty()){
                    c=vt.back(),vt.pop_back();
                    b=pos3[c].first-pos1[c].first;
                    if(b==0)continue;
                    move(pos1[c],make_pair(b/abs(b),0),abs(b));
                }
                b=pos3[a].first-pos1[a].first;
                if(b==0)continue;
                move(pos1[a],make_pair(b/abs(b),0),abs(b));
            }
        }
        while(!vt.empty()){
            c=vt.back(),vt.pop_back();
            b=pos3[c].first-pos1[c].first;
            if(b==0)continue;
            move(pos1[c],make_pair(b/abs(b),0),abs(b));
        }
    }
    for(i=0;i<m;i++){
        pa=make_pair(pos3[i].first,pos1[i].second);
        b=pos3[i].second-pos1[i].second;
        if(b==0)continue;
        move(pa,make_pair(0,b/abs(b)),abs(b));
    }
    for(i=0;i<m;i++){
        b=pos2[i].first-pos3[i].first;
        if(b==0)continue;
        move(pos3[i],make_pair(b/abs(b),0),abs(b));
    }
    for(i=0;i<n;i++){
        for(j=0;j<vb[i].size();j++){
            a=vb[i][j].second;
            if(pos2[a].second>pos3[a].second)vt.push_back(a);
            else{
                while(!vt.empty()){
                    c=vt.back(),vt.pop_back();
                    b=pos2[c].second-pos3[c].second;
                    pa=make_pair(pos2[c].first,pos3[c].second);
                    if(b==0)continue;
                    move(pa,make_pair(0,b/abs(b)),abs(b));
                }
                b=pos2[a].second-pos3[a].second;
                pa=make_pair(pos2[a].first,pos3[a].second);
                if(b==0)continue;
                move(pa,make_pair(0,b/abs(b)),abs(b));
            }
        }
        while(!vt.empty()){
            c=vt.back(),vt.pop_back();
            b=pos2[c].second-pos3[c].second;
            pa=make_pair(pos2[c].first,pos3[c].second);
            if(b==0)continue;
            move(pa,make_pair(0,b/abs(b)),abs(b));
        }
    }
    cout<<vs.size()<<endl;
    for(i=0;i<vs.size();i++){
        tie(a,b,c,d)=vs[i];
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
}