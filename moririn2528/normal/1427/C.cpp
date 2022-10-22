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

int t[110000][5];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    int s=-1;
    cin>>m>>n;
    memset(t,-1,sizeof(t));
    t[0][0]=0,t[0][1]=1,t[0][2]=1,t[0][3]=0;
    for(i=1,k=0;i<=n;i++){
        for(j=0;j<3;j++){
            cin>>t[i][j];
        }
        for(;k<i && t[k][0]<t[i][0]-2*m;k++){
            s=max(s,t[k][3]);
        }
        if(s!=-1)t[i][3]=s+1;
        for(j=k;j<i;j++){
            a=t[i][0]-t[j][0];
            if(abs(t[i][1]-t[j][1])+abs(t[i][2]-t[j][2])<=a){
                if(t[j][3]!=-1)t[i][3]=max(t[i][3],t[j][3]+1);
            }
        }
    }
    for(;k<=n;k++){
        s=max(s,t[k][3]);
    }
    cout<<s<<endl;
}