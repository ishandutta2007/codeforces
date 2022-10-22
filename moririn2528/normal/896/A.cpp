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
const LL MAX=(LL)1<<60;

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
LL num[100005];
string ss[4]={"What are you doing at the end of the world? Are you busy? Will you save us?",
"What are you doing while sending \"",
"\"? Are you busy? Will you send \"",
"\"?"};

char check(LL n,LL m){
    if(n==0)return ss[0][m];

    if(m<34)return ss[1][m];
    m-=34;
    if(num[n-1]>m)return check(n-1,m);
    m-=num[n-1];

    if(m<32)return ss[2][m];
    m-=32;

    if(num[n-1]>m)return check(n-1,m);
    m-=num[n-1];

    return ss[3][m];

}

int main(){
    LL n,m,t;
    LL i,j,k;
    LL a,b,c;
    bool flag;
    num[0]=75;
    for(i=1;i<=1e5;i++){
        num[i]=num[i-1]*2+68;
        if(num[i]>=MAX)num[i]=MAX;
    }
    cin>>t;
    while(t--){
        flag=false;
        cin>>n>>m;
        m--;
        if(m>=num[n])cout<<'.';
        else cout<<check(n,m);
    }
    cout<<endl;
}