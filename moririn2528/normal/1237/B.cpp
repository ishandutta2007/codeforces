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

int t[100005];
int p[100005];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t[i];
        t[i]--;
    }
    for(i=0;i<n;i++){
        cin>>a;
        a--;
        p[a]=i;
    }
    b=-1;
    int s=0;
    for(i=0;i<n;i++){
        a=p[t[i]];
        if(b>a)s++;
        else b=a;
    }
    cout<<s<<endl;
}