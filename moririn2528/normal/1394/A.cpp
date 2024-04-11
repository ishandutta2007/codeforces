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

int main(){
    LL n,m,p;
    int i,j,k;
    LL a,b,c;
    vector<LL> v1,v2;
    cin>>n>>m>>p;
    b=0;
    for(i=0,j=0;i<n;i++){
        cin>>a;
        if(a>p)v1.push_back(a);
        else v2.push_back(a),b+=a;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1.empty()){
        cout<<b<<endl;
        return 0;
    }
    b+=v1.back();
    a=b;
    v1.pop_back();
    for(i=0,j=0;i<v1.size() && (m+1)*(i+1)<=n-1;i++){
        b+=v1[(int)v1.size()-i-1];
        for(k=0;k<m+1;k++,j++){
            if(v1.size()<=j)b-=v2[j-(int)v1.size()];
        }
        a=max(a,b);
    }
    cout<<a<<endl;
}