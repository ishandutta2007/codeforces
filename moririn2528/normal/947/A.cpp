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

bool used[1000005];
LL num[1000005];
vector<LL> pri;

int main(){
    LL n,m;
    LL i,j,k;
    LL a,b,c;
    cin>>n;
    for(i=0;i<=n;i++){
        num[i]=i;
    }
    for(i=2;i<=n;i++){
        if(used[i])continue;
        used[i]=true;
        for(j=i*2;j<=n;j+=i){
            used[j]=true;
            num[j]=min(num[j],j-i+1);
        }
    }
    a=n;
    for(i=num[n];i<=n;i++){
        a=min(a,num[i]);
    }
    cout<<a<<endl;
}