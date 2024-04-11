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
int t[1005];

int main(){
    int n,m,p;
    int i,j,k;
    int a,b,c;
    cin>>n>>m>>p;
    for(i=0;i<m;i++){
        cin>>a;
        if(a<=p/2){
            for(j=0;j<n;j++){
                if(t[j]==0 || t[j]>a)break;
            }
            cout<<j+1<<endl;
            t[j]=a;
        }else{
            for(j=n-1;j>=0;j--){
                if(t[j]==0 || t[j]<a)break;
            }
            cout<<j+1<<endl;
            t[j]=a;
        }
        for(j=0;j<n-1;j++){
            if(t[j]==0 || t[j+1]==0)break;
            if(t[j]>t[j+1])break;
        }
        if(j==n-1)return 0;
    }
}