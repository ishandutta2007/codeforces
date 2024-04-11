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

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c,d;
    cin>>n>>m;
    string sa;
    cin>>sa;
    vector<int> v1;
    a=-1,b=0,c=0,d=0;
    for(i=0;i<n;i++){
        if(sa[i]=='W'){
            if(a==-1)b=i,c--;
            else if(a<i-1)v1.push_back(i-1-a),c--;
            a=i,c+=2;
        }else d++;
    }
    if(d==n){
        if(m)cout<<2*m-1<<endl;
        else cout<<0<<endl;
        return;
    }
    m=min(d,m);
    c+=2*m;
    sort(v1.begin(),v1.end());
    for(i=0;i<v1.size();i++){
        if(m<v1[i])break;
        m-=v1[i],c++;
    }
    cout<<c<<endl;
}

int main(){
    int n,i;
    init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}