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

int bc[2][100005];
int fa[2][100005];

string sa;
bool s[100005];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c,d;
    int p,q,r;
    for(i=0;i<2;i++){
        cin>>sa;
        for(j=0;j<sa.size();j++){
            bc[i][j+1]=bc[i][j];
            if(sa[j]!='A')bc[i][j+1]++;
        }
        for(j=0;j<sa.size();j++){
            if(sa[j]=='A')fa[i][j+1]=fa[i][j]+1;
        }
    }
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        p=(bc[1][d]-bc[1][c-1])-(bc[0][b]-bc[0][a-1]);
        if(p<0 || p%2!=0){
            s[i]=false;
            continue;
        }
        q=min(fa[0][b],b-a+1)-min(fa[1][d],d-c+1);
        if(fa[0][b]>=b-a+1){
            if(p==0 && q>=0 && q%3==0)s[i]=true;
            else if(p>0 && q>=1)s[i]=true;
            else s[i]=false;
        }else{
            if(p==0 && q>=0 && q%3==0)s[i]=true;
            else if(p>0 && q>=0)s[i]=true;
            else s[i]=false;
        }
    }
    for(i=0;i<n;i++){
        if(s[i])cout<<1;
        else cout<<0;
    }
    cout<<endl;
}