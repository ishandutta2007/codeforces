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
#include<complex>
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
    printf("%d ",vec_n);
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    vector<int> v1,v2,vs;
    vector<vector<int>> vt;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    for(i=0;i<(n/2)*2;i++){
        vs.clear();
        for(j=0;j<i/2;j++){
            vs.push_back(1);
        }
        if(i%2==0)a=i/2+1;
        else a=n-i/2;
        for(j=i/2;j<n;j++){
            if(v1[j]==a)break;
        }
        j++;
        vs.push_back(j-i/2);
        a=n-i-(j-i/2);
        if(a)vs.push_back(n-i-(j-i/2));
        for(j=0;j<(i+1)/2;j++){
            vs.push_back(1);
        }
        v2.clear();
        a=n;
        for(j=(int)vs.size()-1;j>=0;j--){
            for(k=a-vs[j];k<a;k++){
                v2.push_back(v1[k]);
            }
            a-=vs[j];
        }
        swap(v1,v2);
        if(vs.size()>=2)vt.push_back(vs);
    }
    cout<<vt.size()<<endl;
    for(i=0;i<vt.size();i++){
        cout<<vt[i].size();
        for(auto num:vt[i]){
            cout<<" "<<num;
        }
        cout<<endl;
    }
}