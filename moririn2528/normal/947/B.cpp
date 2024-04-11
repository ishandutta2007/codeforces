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
void array_show(vector<int> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%d%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%lld%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
LL t[2][100005];
LL tt[100005];
LL num[100005];
vector<pair<LL,LL> > v1;

int main(){
    LL n,m;
    LL i,j,k;
    LL a,b,c;
    cin>>n;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            cin>>t[i][j];
        }
    }
    v1.push_back(make_pair(0,0));
    c=0;
    for(i=0;i<n;i++){
        c+=t[1][i];
        v1.push_back(make_pair(c,i+1));
    }
    
    for(i=0;i<n;i++){
        a=t[0][i]+v1[i].first;
        auto itr=upper_bound(v1.begin(),v1.end(),make_pair(a,n));
        itr--;
        b=a-itr->first;
        c=itr->second;
        tt[i]++,tt[c]--;
        num[c]+=b;
    }
    for(i=0;i<=n;i++){
        tt[i+1]+=tt[i];
        num[i]+=tt[i]*t[1][i];
    }
    array_show(num,n);
}