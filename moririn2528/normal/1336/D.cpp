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

vector<P> vt;
int x,y;
void ques(int i){
    int a,b;
    cout<<"+ "<<i+1<<endl;
    cin>>a>>b;
    vt.push_back(make_pair(a-x,b-y));
    x=a,y=b;
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c,d,e,f;
    int p,q;
    cin>>n;
    vector<int> vs(n),v1(n);
    cin>>x>>y;
    bool odd=false;
    for(i=n-2;i>=2;i--)ques(i);
    ques(0);
    ques(1);
    ques(0);
    reverse(vt.begin(),vt.end());
    vs[0]=sqrt(vt[0].first*2);
    vs[2]=vt[0].second-vt[2].second-1;
    vs[1]=vt[2].second/(vs[2]+1);
    vs[3]=(vt[1].second-(vs[0]+1)*(vs[2]+1))/(vs[2]+1)-1;
    for(i=4;i<n;i++){
        a=vt[i-1].second-vs[i-4]*vs[i-3]-vs[i-3]*(vs[i-1]+1);
        vs[i]=a/(vs[i-1]+1)-1;
    }
    vs.back()++;
    cout<<"!";
    for(i=0;i<n;i++){
        cout<<" "<<vs[i];
    }
    cout<<endl;
}