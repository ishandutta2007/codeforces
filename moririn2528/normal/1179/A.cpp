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
#include<deque>
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

deque<int> d1;
int s[100005][2];
vector<int> v1;

int main(){
    LL n,m;
    int i,j,k;
    LL a,b,c;
    LL x,y;
    cin>>n>>m;
    b=0;
    for(i=0;i<n;i++){
        cin>>a;
        b=max(b,a);
        d1.push_back(a);
    }
    for(j=0;d1.front()!=b;j++){
        x=d1.front(),d1.pop_front();
        y=d1.front(),d1.pop_front();
        s[j][0]=x,s[j][1]=y;
        if(x>y)d1.push_front(x),d1.push_back(y);
        else d1.push_front(y),d1.push_back(x);
    }
    d1.pop_front();
    for(i=0;i<n-1;i++){
        a=d1.front(),d1.pop_front();
        v1.push_back(a);
    }
    for(i=0;i<m;i++){
        cin>>a;
        if(a<=j){
            cout<<s[a-1][0]<<" "<<s[a-1][1]<<endl;
        }else{
            a-=j+1;
            a%=n-1;
            cout<<b<<" "<<v1[a]<<endl;
        }
    }
}