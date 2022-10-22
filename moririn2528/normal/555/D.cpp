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

namespace sol{

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        cin>>n>>m;
        vector<LP> va;
        vector<LL> pos,ids(n);
        for(i=0;i<n;i++){
            cin>>a;
            va.push_back({a,i});
            pos.push_back(a);
        }
        sort(va.begin(),va.end());
        sort(pos.begin(),pos.end());
        for(i=0;i<n;i++){
            ids[va[i].second]=i;
        }
        vector<int> v1(n),v2(n),u1(n,-1),u2(n,-1);
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--;
            a=ids[a];
            bool flag=true;
            int cnt=0;
            auto itr=pos.begin();
            while(1){
                if(flag){
                    if(u1[a]==i)b%=v1[a]-b;
                    v1[a]=b,u1[a]=i;
                    itr=upper_bound(pos.begin(),pos.end(),pos[a]+b);
                    itr--;
                }else{
                    if(u2[a]==i)b%=v2[a]-b;
                    v2[a]=b,u2[a]=i;
                    itr=lower_bound(pos.begin(),pos.end(),pos[a]-b);
                }
                if(itr-pos.begin()==a)cnt++;
                else cnt=0;
                b-=abs(*itr-pos[a]);
                a=itr-pos.begin();
                flag=!flag;
                if(cnt>=2)break;
            }
            cout<<va[a].second+1<<endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}