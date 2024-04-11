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
 
vector<tuple<int,int,int,int> > v1;
vector<P> vs;
vector<int> v2;
int out_num,out_b;
void out(int a){
    out_num++;
    if(out_num%2==1)out_b=a;
    else vs.push_back(make_pair(out_b,a));
}
 
int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    int p,q;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b>>c;
        v1.push_back(make_tuple(a,b,c,i));
    }
    sort(v1.begin(),v1.end());
    for(i=0;i<v1.size();i=p){
        tie(a,b,c,k)=v1[i];
        for(p=i+1;p<v1.size() && a==get<0>(v1[p]);p++);
        v2.clear();
        for(j=i;j<p;j=q){
            tie(a,b,c,k)=v1[j];
            for(q=j+1;q<p && b==get<1>(v1[q]);q++);
            for(k=j;k+1<q;k+=2){
                vs.push_back(make_pair(get<3>(v1[k]),get<3>(v1[k+1])));
            }
            if(k<q)v2.push_back(get<3>(v1[k]));
        }
        for(j=0;j+1<v2.size();j+=2){
            vs.push_back(make_pair(v2[j],v2[j+1]));
        }
        if(j<v2.size())out(v2[j]);
    }
    for(auto &it:vs){
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }
}