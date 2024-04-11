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

LL t[2][330000];

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    LL s=0;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    c=0;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            cin>>t[i][j];
            if(i==0)s+=t[i][j]*j;
            else s+=t[i][j]*(2*n-j-1);
            c+=t[i][j];
        }
    }
    a=s,b=0;
    for(i=0;i<n;i++){
        a=c*(2*(n-i)-1)-a;
        c-=t[0][i]+t[1][i];
        a-=c;
        a-=t[i%2][i]*(2*(n-i)-1);
        
        b+=(2*i)*t[i%2][i]+(2*i+1)*t[1-i%2][i];
        s=max(s,a+b+2*(i+1)*c);
    }
    cout<<s<<endl;
}