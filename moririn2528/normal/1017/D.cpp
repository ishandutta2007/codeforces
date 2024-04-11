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

int t[1<<12][110];
int cnt[1<<12];
int cs[20];
int cs2[1<<12];

int to_int(string& sa){
    int a=0;
    for(int j=0;j<sa.size();j++){
        if(sa[j]=='1')a+=1<<(sa.size()-j-1);
    }
    return a;
}

int main(){
    int n,m,q;
    int i,j,k;
    int a,b,c;
    string sa;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(i=0;i<n;i++){
        cin>>cs[i];
    }
    for(i=0;i<m;i++){
        cin>>sa;
        cnt[to_int(sa)]++;
    }
    for(i=0;i<(1<<n);i++){
        b=0;
        for(k=0;k<n;k++){
            if(i&(1<<(n-k-1)))b+=cs[k];
        } 
        cs2[i]=b;
    }
    for(i=0;i<(1<<n);i++){
        for(j=0;j<(1<<n);j++){
            a=i^j;
            a=(1<<n)-a-1;
            b=cs2[a];
            if(b<=100)t[i][b]+=cnt[j];
        }
        for(j=0;j<100;j++){
            t[i][j+1]+=t[i][j];
        }
    }
    
    for(i=0;i<q;i++){
        cin>>sa>>a;
        cout<<t[to_int(sa)][a]<<endl;
    }
}