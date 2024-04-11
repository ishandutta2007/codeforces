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

const int N=110000;
long double t[120000];
long double su[120000];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    long double da,db;
    int q=0;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    if(m==1){
        cout<<1<<endl;
        return 0;
    }
    for(i=0;i<N;i++)su[i]=1;
    for(i=0;i<n;i++){
        cin>>a;
        q+=a;
        a--;
        for(j=0;j<N;j++){
            db=0;
            if(a<j)db+=su[j-a-1];
            if(m<=j)db-=su[j-m];
            db+=su[j];
            if(a<=j)db-=su[j-a];
            t[j+1]=db/(m-1);
        }
        su[0]=t[0];
        for(j=1;j<N;j++){
            su[j]=su[j-1]+t[j];
        }
    }
    da=0;
    for(i=0;i<q;i++){
        da+=t[i];
    }
    cout<<fixed<<setprecision(20);
    cout<<da*(m-1)+1<<endl;
}