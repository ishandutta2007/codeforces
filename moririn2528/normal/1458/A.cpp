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

long long int gcd(long long int a,long long int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    vector<LL> v1,v2,vs;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    for(i=0;i<m;i++){
        cin>>a;
        v2.push_back(a);
    }
    a=0;
    for(i=0;i<n-1;i++){
        a=gcd(a,abs(v1[i+1]-v1[i]));
    }
    for(i=0;i<m;i++){
        b=gcd(a,v2[i]+v1[0]);
        if(i)cout<<" ";
        cout<<b;
    }
    cout<<endl;
}