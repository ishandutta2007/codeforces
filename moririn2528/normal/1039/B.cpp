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
#include<random>
#include<ctime>
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

const int N=4500,M=50;

bool check(){
    string sa;
    cin>>sa;
    if(sa=="Yes")return true;
    return false;
}

int main(){
    LL n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n>>m;
    a=0,b=n-1;
    srand(time(NULL));
    for(i=0;i<N;i++){
        if(b-a<=M){
            if(a==b)c=a+1;
            else c=rand()%(b-a+1)+a+1;
            cout<<c<<" "<<c<<endl;
            if(check())return 0;
            a=max(a-m,(LL)0),b=min(b+m,n-1);
            continue;
        }
        c=(a+b)/2;
        cout<<a+1<<" "<<c+1<<endl;
        if(check())b=c;
        else a=c+1;
        a=max(a-m,(LL)0),b=min(b+m,n-1);
    }
}