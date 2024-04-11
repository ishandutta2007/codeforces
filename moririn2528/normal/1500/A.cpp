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
    int s[5100000][2];

    bool check(int i,int j,int id){
        i++,j++;
        for(int k=0;k<2;k++){
            if(s[id][k]==i || s[id][k]==j)return false;
        }
        return true;
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<int> v1;
        for(i=0;i<n;i++){
            cin>>a;
            v1.push_back(a);
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                a=v1[i]+v1[j];
                if(s[a][0] && check(i,j,a)){
                    cout<<"YES"<<endl;
                    cout<<s[a][0]<<" "<<s[a][1]<<" "<<i+1<<" "<<j+1<<endl;
                    return;
                }
                s[a][0]=i+1,s[a][1]=j+1;
            }
        }
        cout<<"NO"<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}