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

    void reverse01(string& sa){
        for(auto& ca:sa){
            if(ca=='0')ca++;
            else ca--;
        }
    }

    int count0(string& sa){
        int s=0;
        for(auto ca:sa){
            if(ca=='0')s++;
        }
        return s;
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        constexpr int N=3;
        string sa[N];
        vector<P> vp;
        cin>>n;
        for(i=0;i<N;i++){
            cin>>sa[i];
        }
        for(i=0;i<2;i++){
            vp.clear();
            for(j=0;j<N;j++){
                vp.push_back({count0(sa[j]),j});
            }
            sort(vp.begin(),vp.end());
            if(vp[1].first<=n)break;
            for(j=0;j<N;j++)reverse01(sa[j]);
        }
        bool reversed=i;
        string sb=sa[vp[0].second],ss;
        vector<int> v1={0};
        for(auto ca:sa[vp[1].second]){
            if(ca=='0')v1.back()++;
            else v1.push_back(0);
        }
        for(i=0;i<v1[0];i++)ss.push_back('0');
        for(i=0,j=0;i<sb.size();i++){
            ss.push_back(sb[i]);
            if(sb[i]=='1'){
                j++;
                for(k=0;j<v1.size() && k<v1[j];k++){
                    ss.push_back('0');
                }
            }
        }
        while(ss.size()<3*n)ss.push_back('0');
        if(reversed)reverse01(ss);
        cout<<ss<<endl;
    }
}

int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}