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

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        int x,y;
        cin>>n>>m;
        string sa,sb;
        cin>>sa>>sb;
        vector<P> v1;
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--;
            v1.push_back(make_pair(a,b));
        }
        reverse(v1.begin(),v1.end());
        map<int,P> m1;
        for(i=0;i<n;i++){
            m1[i]=make_pair(1,(int)sb[i]-(int)'0');
        }
        for(i=0;i<m;i++){
            a=v1[i].first,b=v1[i].second,c=0;
            auto itr=m1.begin();
            if(m1.find(a)==m1.end()){
                itr=m1.lower_bound(a);
                itr--;
                x=itr->first+itr->second.first-a;
                itr->second.first=a-itr->first;
                m1[a]=make_pair(x,itr->second.second);
            }
            while(1){
                itr=m1.lower_bound(a);
                if(itr==m1.end() || itr->first>=b)break;
                y=min(b,itr->first+itr->second.first);
                x=y-itr->first;
                y=itr->first+itr->second.first-y;
                if(itr->second.second==1)c+=x;
                x=itr->second.second;
                m1.erase(itr);
                if(y)m1[b]=make_pair(y,x);
            }
            if(c*2==b-a){
                cout<<"No"<<endl;
                return;
            }
            if(c*2<(b-a))m1[a]=make_pair(b-a,0);
            else m1[a]=make_pair(b-a,1);
        }
        for(auto itr:m1){
            b=itr.second.second;
            for(i=itr.first;i<itr.first+itr.second.first;i++){
                a=sa[i]-(int)'0';
                if(a!=b){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
        cout<<"Yes"<<endl;
    }
}

int main(){
    int n,i;
    sol::init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}