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
#include<numeric>
#include<functional>
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
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    vector<int> t(n);
    vector<int> vs(n);
    map<int,int> m1;
    for(i=1;i<n;i++){
        cout<<"XOR 1 "<<i+1<<endl;
        cin>>a;
        t[i]=a;
    }
    for(i=1;i<n;i++){
        if(t[i]==0){
            cout<<"AND 1 "<<i+1<<endl;
            cin>>a;
            vs[0]=a;
            break;
        }
        if(m1.find(t[i])!=m1.end()){
            j=m1[t[i]];
            cout<<"AND "<<i+1<<" "<<j+1<<endl;
            cin>>a;
            vs[0]=t[i]^a;
            break;
        }
        m1[t[i]]=i;
    }
    if(i==n){
        j=m1[1];
        cout<<"AND 1 "<<j+1<<endl;
        cin>>a;
        a&=n-2;
        j=m1[n-2];
        cout<<"AND 1 "<<j+1<<endl;
        cin>>b;
        b&=1;
        vs[0]=a+b;
    }
    for(i=1;i<n;i++){
        vs[i]=vs[0]^t[i];
    }
    cout<<"!";
    for(i=0;i<n;i++){
        cout<<" "<<vs[i];
    }
    cout<<endl;
}