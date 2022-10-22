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

void init(){
    
}

int t[555];
bool good[555];

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n>>m;
    memset(good,false,sizeof(good));
    for(i=0;i<n;i++){
        cin>>t[i];
    }
    for(i=n-1;i>=0;i--){
        good[i]=true;
        if(i && t[i-1]>t[i])break;
    }
    int s=0;
    if(good[0]){
        cout<<0<<endl;
        return;
    }
    for(i=0;i<n;i++){

        if(i && t[i-1]<=t[i] && good[i]){
            cout<<s<<endl;
            return;
        }
        if(t[i]>m)swap(t[i],m),s++;
        if(i && t[i-1]>t[i])break;
    }
    cout<<-1<<endl;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}