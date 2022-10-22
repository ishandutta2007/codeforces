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

vector<int> path[300005];
int t[300005];
bool used[300005];
int num[300005];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>t[i];
        t[i]--;
    }
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        path[b].push_back(a);
        if(b==t[n-1])used[a]=true;
    }
    for(i=n-2;i>=0;i--){
        if(!used[t[i]])break;
    }
    if(i==-1){
        cout<<n-1<<endl;
        return 0;
    }
    a=n-i-2;
    for(j=0;i>=0;i--){
        if(j!=0 && num[t[i]]==j && used[t[i]])a++;
        else{
            j++;
            for(auto p:path[t[i]])num[p]++;
        }
    }
    cout<<a<<endl;
}