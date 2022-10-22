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
typedef pair<LL,LL> P;
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

LL t[110000];
LL di[110000];

LL calc(LL n,LL i){
    LL a=n/i,b=n%i;
    return a*a*(i-b)+(a+1)*(a+1)*b;
}

int main(){
    LL n,m;
    int i,j,k;
    LL a,b,c;
    LL s=0;
    priority_queue<P> q1;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>t[i];
        di[i]=1;
        s+=t[i]*t[i];
        q1.push(make_pair(calc(t[i],1)-calc(t[i],2),i));
    }
    for(i=n;i<m;i++){
        a=q1.top().first,b=q1.top().second;q1.pop();
        s-=a;
        di[b]++;
        q1.push(make_pair(calc(t[b],di[b])-calc(t[b],di[b]+1),b));
    }
    cout<<s<<endl;
}