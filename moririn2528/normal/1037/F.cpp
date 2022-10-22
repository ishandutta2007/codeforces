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

LL calc(LL dis,LL m){
    m--;
    LL n=dis/m+1;
    return (dis+dis-m*(n-1))*n/2%MAX;
}

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    LL s=0;
    vector<P> vp;
    set<int> s1;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",&a);
        vp.push_back(make_pair(a,i));
        s+=a;
    }
    s%=MAX;
    s=-s;
    sort(vp.rbegin(),vp.rend());
    s1.insert(-1),s1.insert(n);
    for(i=0;i<n;i++){
        a=vp[i].second;
        auto itr=s1.lower_bound(a);
        b=*itr;
        itr--;
        c=*itr;
        s1.insert(a);
        a=calc(b-c-1,m)-calc(b-a-1,m)-calc(a-c-1,m);
        if(a<0)a+=2*MAX;
        s+=a%MAX*vp[i].first%MAX;
        
    }
    if(s<0)s+=MAX;
    s%=MAX;
    printf("%lld\n",s);
}