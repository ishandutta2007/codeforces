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

string sa,sb;
int t[200005];
bool used[200005];

int pos=0;
bool check(int x){
    int i,j;
    if(pos<x){
        for(i=pos;i<x;i++){
            used[t[i]]=true;
        }
    }else{
        for(i=x;i<=pos;i++){
            used[t[i]]=false;
        }
    }
    pos=x;
    j=0;
    for(i=0;i<sa.size();i++){
        if(used[i])continue;
        if(j>=sb.size())break;
        if(sa[i]==sb[j])j++;
    }
    if(j>=sb.size())return true;
    return false;
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>sa>>sb;
    for(i=0;i<sa.size();i++){
        cin>>t[i];
        t[i]--;
    }
    a=-1,b=sa.size();
    while(b-a>1){
        c=(b+a)/2;
        if(check(c))a=c;
        else b=c;
    }
    cout<<a<<endl;
}