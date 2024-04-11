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

int main(){
    LL n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n>>m;
    vector<LL> va(n),vx(n),vb(n);
    for(i=0;i<n;i++){
        cin>>va[i];
    }
    for(i=0;i<n;i++){
        cin>>vx[i];
        vx[i]--;
        if(vx[i]<i || (i>0 && vx[i]<vx[i-1])){
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(i=0;i<n;i++){
        j=vx[i];
        if(vx[j]!=j){
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(i=0;i<n;i++){
        if(vx[i]==i){
            vb[i]=va[i]+m;
            if(i>0 && vb[i-1]>=vb[i])vb[i]=vb[i-1]+1;
            if(i<n-1 && vb[i]>=va[i+1]+m){
                cout<<"No"<<endl;
                return 0;
            }
        }else vb[i]=va[i+1]+m;
    }
    cout<<"Yes"<<endl;
    array_show(vb);
}