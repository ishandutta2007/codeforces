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

char ca[300005];

int main(){
    LL n,m;
    int i,j,k;
    LL a,b,c;
    LL x,y;
    LL s;
    cin>>n>>x>>y;
    cin>>ca;
    a=0,b=0;
    for(i=0;i<n;i++){
        if(ca[i]=='0')b=1;
        else if(b==1)a++,b=0;
    }
    if(b==1)a++;
    if(a==0)s=0;
    else if(x<y)s=x*(a-1)+y;
    else s=a*y;
    cout<<s<<endl;
}