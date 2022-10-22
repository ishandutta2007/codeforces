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

LL A[30][30];

int main(){
    int n,m;
    LL i,j,k;
    LL a,b,c;
    vector<P> v1;
    cin>>n;
    i=32;
    for(i=0;i<2*n-2;i++){
        j=0;
        if(i>=n)j=i-n+1;
        for(;i-j>=0 && j<n;j++){
            if(j%2)A[j][i-j]=((LL)1<<i);
        }
    }
    for(i=0;i<n;i++){
        array_show(A[i],n);
    }
    cin>>m;
    for(i=0;i<m;i++){
        cin>>a;
        v1.clear();
        j=0,k=0;
        while(j<n && k<n){
            v1.push_back(make_pair(j+1,k+1));
            if(j==n-1)k++;
            else if(k==n-1)j++;
            else if((A[j+1][k]^a)&((LL)1<<(j+k+1))){
                k++;
            }else j++;
        }
        for(j=0;j<v1.size();j++){
            cout<<v1[j].first<<" "<<v1[j].second<<endl;
        }
    }
}