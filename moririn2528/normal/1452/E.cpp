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

int t[2222][2];
const int N=2222;
int tt[6666];

int intersect(int a,int b,int x,int y){
    int l=max(a,x),r=min(b,y);
    if(l>r)return 0;
    return r-l;
}

int main(){
    int n,m,p;
    int i,j,k;
    int a,b,c;
    cin>>n>>m>>p;
    for(i=0;i<m;i++){
        for(j=0;j<2;j++){
            cin>>t[i][j];
        }
        t[i][0]--;
    }
    int s=0;
    for(i=0;i<=n-p;i++){
        c=0;
        memset(tt,0,sizeof(tt));
        for(j=0;j<m;j++){
            a=intersect(i,i+p,t[j][0],t[j][1]);
            b=p-a;
            c+=a;
            tt[N+t[j][0]-b+1]++;
            tt[N+t[j][0]+1]--;
            tt[N+t[j][1]-p+1]--;
            tt[N+t[j][1]-p+b+1]++;
        }
        for(j=0;j<2;j++){
            for(k=0;k<6600;k++){
                tt[k+1]+=tt[k];
            }
        }
        
        for(j=N;j<=N+n-p;j++){
            
            s=max(s,c+tt[j]);
        }
        
    }
    cout<<s<<endl;
}